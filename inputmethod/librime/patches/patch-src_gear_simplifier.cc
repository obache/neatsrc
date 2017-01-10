$NetBSD$

* Upstream update for upencc 1.0.0

--- src/gear/simplifier.cc.orig	2014-07-14 07:17:53.000000000 +0000
+++ src/gear/simplifier.cc
@@ -8,7 +8,12 @@
 #include <vector>
 #include <boost/algorithm/string.hpp>
 #include <boost/filesystem.hpp>
-#include <opencc/opencc.h>
+#include <opencc/Config.hpp>
+#include <opencc/Converter.hpp>
+#include <opencc/Conversion.hpp>
+#include <opencc/ConversionChain.hpp>
+#include <opencc/Dict.hpp>
+#include <opencc/DictEntry.hpp>
 #include <stdint.h>
 #include <utf8.h>
 #include <rime/candidate.h>
@@ -27,67 +32,40 @@ namespace rime {
 
 class Opencc {
  public:
-  Opencc(const std::string& config_path);
-  ~Opencc();
-  bool ConvertText(const std::string& text,
-                   std::string* simplified,
-                   bool* is_single_char);
-
- private:
-  opencc_t od_;
-};
-
-Opencc::Opencc(const std::string& config_path) {
-  LOG(INFO) << "initilizing opencc: " << config_path;
-  od_ = opencc_open(config_path.c_str());
-  if (od_ == (opencc_t) -1) {
-    LOG(ERROR) << "Error opening opencc.";
+  Opencc(const std::string& config_path) {
+    LOG(INFO) << "initilizing opencc: " << config_path;
+    opencc::Config config;
+    converter_ = config.NewFromFile(config_path);
+    const std::list<opencc::ConversionPtr> conversions =
+      converter_->GetConversionChain()->GetConversions();
+    dict_ = conversions.front()->GetDict();
+  }
+
+  bool ConvertSingleCharacter(const std::string& text,
+                              std::vector<std::string>* forms) {
+    opencc::Optional<const opencc::DictEntry*> item = dict_->Match(text);
+    if (item.IsNull()) {
+      // Match not found
+      return false;
+    } else {
+      const opencc::DictEntry* entry = item.Get();
+      for (const char* value : entry->Values()) {
+        forms->push_back(value);
+      }
+      return true;
+    }
   }
-}
 
-Opencc::~Opencc() {
-  if (od_ != (opencc_t) -1) {
-    opencc_close(od_);
+  bool ConvertText(const std::string& text,
+                   std::string* simplified) {
+    *simplified = converter_->Convert(text);
+    return true;
   }
-}
 
-bool Opencc::ConvertText(const std::string& text,
-                         std::string* simplified,
-                         bool* is_single_char) {
-  if (od_ == (opencc_t) -1)
-    return false;
-  unique_ptr<uint32_t[]> inbuf(new uint32_t[text.length() + 1]);
-  uint32_t* end = utf8::unchecked::utf8to32(text.c_str(),
-                                            text.c_str() + text.length(),
-                                            inbuf.get());
-  *end = L'\0';
-  size_t inlen = end - inbuf.get();
-  uint32_t* inptr = inbuf.get();
-  size_t outlen = inlen * 5;
-  unique_ptr<uint32_t[]> outbuf(new uint32_t[outlen + 1]);
-  uint32_t* outptr = outbuf.get();
-  if (inlen == 1) {
-    *is_single_char = true;
-    opencc_set_conversion_mode(od_, OPENCC_CONVERSION_LIST_CANDIDATES);
-  }
-  else {
-    *is_single_char = false;
-    opencc_set_conversion_mode(od_, OPENCC_CONVERSION_FAST);
-  }
-  size_t converted = opencc_convert(od_, &inptr, &inlen, &outptr, &outlen);
-  if (!converted) {
-    LOG(ERROR) << "Error simplifying '" << text << "'.";
-    return false;
-  }
-  *outptr = L'\0';
-  unique_ptr<char[]> out_utf8(new char[(outptr - outbuf.get()) * 6 + 1]);
-  char* utf8_end = utf8::unchecked::utf32to8(outbuf.get(),
-                                             outptr,
-                                             out_utf8.get());
-  *utf8_end = '\0';
-  *simplified = out_utf8.get();
-  return true;
-}
+ private:
+   opencc::ConverterPtr converter_;
+   opencc::DictPtr dict_;
+};
 
 // Simplifier
 
@@ -117,7 +95,7 @@ Simplifier::Simplifier(const Ticket& tic
     option_name_ = "simplification";  // default switcher option
   }
   if (opencc_config_.empty()) {
-    opencc_config_ = "zht2zhs.ini";  // default opencc config file
+    opencc_config_ = "t2s.json";  // default opencc config file
   }
 }
 
@@ -125,6 +103,10 @@ void Simplifier::Initialize() {
   using namespace boost::filesystem;
   initialized_ = true;  // no retry
   path opencc_config_path = opencc_config_;
+  if (opencc_config_path.extension().string() == ".ini") {
+    LOG(ERROR) << "please upgrade opencc_config to an opencc 1.0 config file.";
+    return;
+  }
   if (opencc_config_path.is_relative()) {
     path user_config_path = Service::instance().deployer().user_data_dir;
     path shared_config_path = Service::instance().deployer().shared_data_dir;
@@ -137,7 +119,12 @@ void Simplifier::Initialize() {
       opencc_config_path = shared_config_path;
     }
   }
-  opencc_.reset(new Opencc(opencc_config_path.string()));
+  try {
+    opencc_.reset(new Opencc(opencc_config_path.string()));
+  }
+  catch (opencc::Exception& e) {
+    LOG(ERROR) << "Error initializing opencc: " << e.what();
+  }
 }
 
 void Simplifier::Apply(CandidateList* recruited,
@@ -161,15 +148,16 @@ bool Simplifier::Convert(const shared_pt
   if (excluded_types_.find(original->type()) != excluded_types_.end()) {
     return false;
   }
-  std::string simplified;
-  bool is_single_char = false;
-  if (!opencc_->ConvertText(original->text(), &simplified, &is_single_char) ||
-      simplified == original->text()) {
-    return false;
-  }
-  if (is_single_char) {
+  size_t length = utf8::unchecked::distance(original->text().c_str(),
+                                            original->text().c_str()
+                                            + original->text().length());
+  bool success;
+  if (length == 1) {
     std::vector<std::string> forms;
-    boost::split(forms, simplified, boost::is_any_of(" "));
+    success = opencc_->ConvertSingleCharacter(original->text(), &forms);
+    if (!success || forms.size() == 0) {
+      return false;
+    }
     for (size_t i = 0; i < forms.size(); ++i) {
       if (forms[i] == original->text()) {
         result->push_back(original);
@@ -187,8 +175,12 @@ bool Simplifier::Convert(const shared_pt
                 tips));
       }
     }
-  }
-  else {
+  } else {
+    std::string simplified;
+    success = opencc_->ConvertText(original->text(), &simplified);
+    if (!success || simplified == original->text()) {
+      return false;
+    }
     std::string tips;
     if (tips_level_ == kTipsAll) {
       tips = quote_left + original->text() + quote_right;
