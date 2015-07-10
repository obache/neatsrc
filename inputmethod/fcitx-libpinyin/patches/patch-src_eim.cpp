$NetBSD$

* bind_text_domain_codeset to utf8
* update for compatible with new libpinyin
* add phrase to acutual user dictionary

--- src/eim.cpp.orig	2013-07-15 20:34:05.000000000 +0000
+++ src/eim.cpp
@@ -353,11 +353,12 @@ void FcitxLibPinyinLoad(FcitxLibPinyin* 
     if (libpinyin->type == LPT_Zhuyin && libpinyin->owner->zhuyin_context == NULL) {
         char* user_path = FcitxLibPinyinGetUserPath(libpinyinaddon->config.bSimplifiedDataForZhuyin ? LPLT_Simplified : LPLT_Traditional);
         char* syspath = FcitxLibPinyinGetSysPath(libpinyinaddon->config.bSimplifiedDataForZhuyin ? LPLT_Simplified : LPLT_Traditional);
-        libpinyinaddon->zhuyin_context = pinyin_init(syspath, user_path);
+        libpinyinaddon->zhuyin_context = pinyin_init(syspath, user_path);/*
+        pinyin_load_phrase_library(libpinyinaddon->zhuyin_context, GB_DICTIONARY);
         pinyin_load_phrase_library(libpinyinaddon->zhuyin_context, GBK_DICTIONARY);
-        pinyin_load_phrase_library(libpinyinaddon->zhuyin_context, MERGED_DICTIONARY);
-        pinyin_load_phrase_library(libpinyinaddon->zhuyin_context, 14);
+        pinyin_load_phrase_library(libpinyinaddon->zhuyin_context, ADDON_DICTIONARY);
         pinyin_load_phrase_library(libpinyinaddon->zhuyin_context, USER_DICTIONARY);
+        pinyin_load_phrase_library(libpinyinaddon->zhuyin_context, NETWORK_DICTIONARY);*/
         free(user_path);
         free(syspath);
     }
@@ -365,11 +366,12 @@ void FcitxLibPinyinLoad(FcitxLibPinyin* 
     if (libpinyin->type != LPT_Zhuyin && libpinyin->owner->pinyin_context == NULL) {
         char* user_path = FcitxLibPinyinGetUserPath(libpinyinaddon->config.bTraditionalDataForPinyin ? LPLT_Traditional : LPLT_Simplified);
         char* syspath = FcitxLibPinyinGetSysPath(libpinyinaddon->config.bTraditionalDataForPinyin ? LPLT_Traditional : LPLT_Simplified);
-        libpinyinaddon->pinyin_context = pinyin_init(syspath, user_path);
+        libpinyinaddon->pinyin_context = pinyin_init(syspath, user_path);/*
+        pinyin_load_phrase_library(libpinyinaddon->pinyin_context, GB_DICTIONARY);
         pinyin_load_phrase_library(libpinyinaddon->pinyin_context, GBK_DICTIONARY);
-        pinyin_load_phrase_library(libpinyinaddon->pinyin_context, MERGED_DICTIONARY);
-        pinyin_load_phrase_library(libpinyinaddon->pinyin_context, 14);
+        pinyin_load_phrase_library(libpinyinaddon->pinyin_context, ADDON_DICTIONARY);
         pinyin_load_phrase_library(libpinyinaddon->pinyin_context, USER_DICTIONARY);
+        pinyin_load_phrase_library(libpinyinaddon->pinyin_context, NETWORK_DICTIONARY);*/
         free(user_path);
         free(syspath);
     }
@@ -770,7 +772,7 @@ void* LibPinyinSavePinyinWord(void* arg,
     }
 
     if (ss.str().length() > 0) {
-        import_iterator_t* iter = pinyin_begin_add_phrases(context, 15);
+        import_iterator_t* iter = pinyin_begin_add_phrases(context, USER_DICTIONARY);
         if (iter) {
             char* hz = (char*) args.args[0];
             pinyin_iterator_add_phrase(iter, hz, ss.str().c_str(), -1);
@@ -792,6 +794,7 @@ void* FcitxLibPinyinCreate(FcitxInstance
 {
     FcitxLibPinyinAddonInstance* libpinyinaddon = (FcitxLibPinyinAddonInstance*) fcitx_utils_malloc0(sizeof(FcitxLibPinyinAddonInstance));
     bindtextdomain("fcitx-libpinyin", LOCALEDIR);
+    bind_textdomain_codeset("fcitx-libpinyin", "UTF-8");
     libpinyinaddon->owner = instance;
     FcitxAddon* addon = FcitxAddonsGetAddonByName(FcitxInstanceGetAddons(instance), "fcitx-libpinyin");
 
@@ -892,11 +895,11 @@ void FcitxLibPinyinReconfigure(FcitxLibP
     if (libpinyinaddon->zhuyin_context) {
         pinyin_set_chewing_scheme(libpinyinaddon->zhuyin_context, FcitxLibPinyinTransZhuyinLayout(config->zhuyinLayout));
 
-        for (int i = 0; i <= FCITX_DICT_LAST; i++) {
-            if (config->dict[i]) {
-                pinyin_load_phrase_library(libpinyinaddon->zhuyin_context, FcitxLibPinyinTransDictionary(static_cast<FCITX_DICTIONARY>(i)));
+        for (int i = 0; i <= FCITX_ZHUYIN_DICT_LAST; i++) {
+            if (config->dict_zhuyin[i]) {
+                pinyin_load_addon_phrase_library(libpinyinaddon->zhuyin_context, FcitxLibPinyinTransZhuyinDictionary(static_cast<FCITX_ZHUYIN_DICTIONARY>(i)));
             } else {
-                pinyin_unload_phrase_library(libpinyinaddon->zhuyin_context, FcitxLibPinyinTransDictionary(static_cast<FCITX_DICTIONARY>(i)));
+                pinyin_unload_addon_phrase_library(libpinyinaddon->zhuyin_context, FcitxLibPinyinTransZhuyinDictionary(static_cast<FCITX_ZHUYIN_DICTIONARY>(i)));
             }
         }
     }
@@ -904,9 +907,9 @@ void FcitxLibPinyinReconfigure(FcitxLibP
         pinyin_set_double_pinyin_scheme(libpinyinaddon->pinyin_context, FcitxLibPinyinTransShuangpinScheme(config->spScheme));
         for (int i = 0; i <= FCITX_DICT_LAST; i++) {
             if (config->dict[i]) {
-                pinyin_load_phrase_library(libpinyinaddon->pinyin_context, FcitxLibPinyinTransDictionary(static_cast<FCITX_DICTIONARY>(i)));
+                pinyin_load_addon_phrase_library(libpinyinaddon->pinyin_context, FcitxLibPinyinTransDictionary(static_cast<FCITX_DICTIONARY>(i)));
             } else {
-                pinyin_unload_phrase_library(libpinyinaddon->pinyin_context, FcitxLibPinyinTransDictionary(static_cast<FCITX_DICTIONARY>(i)));
+                pinyin_unload_addon_phrase_library(libpinyinaddon->pinyin_context, FcitxLibPinyinTransDictionary(static_cast<FCITX_DICTIONARY>(i)));
             }
         }
     }
@@ -969,10 +972,11 @@ void FcitxLibPinyinClearData(FcitxLibPin
 
     switch (type) {
     case 0:
-        pinyin_mask_out(context, PHRASE_INDEX_LIBRARY_MASK, PHRASE_INDEX_MAKE_TOKEN(15, null_token));
+        pinyin_mask_out(context, PHRASE_INDEX_LIBRARY_MASK, PHRASE_INDEX_MAKE_TOKEN(USER_DICTIONARY, null_token));
+        pinyin_mask_out(context, PHRASE_INDEX_LIBRARY_MASK, PHRASE_INDEX_MAKE_TOKEN(ADDON_DICTIONARY, null_token));
         break;
     case 1:
-        pinyin_mask_out(context, PHRASE_INDEX_LIBRARY_MASK, PHRASE_INDEX_MAKE_TOKEN(14, null_token));
+        pinyin_mask_out(context, PHRASE_INDEX_LIBRARY_MASK, PHRASE_INDEX_MAKE_TOKEN(NETWORK_DICTIONARY, null_token));
         break;
     case 2:
         pinyin_mask_out(context, 0, 0);
@@ -999,9 +1003,9 @@ void FcitxLibPinyinImport(FcitxLibPinyin
 
     const char* path = langType == LPLT_Simplified ? "libpinyin/importdict" : "libpinyin/importdict_zhuyin";
 
-    pinyin_mask_out(context, PHRASE_INDEX_LIBRARY_MASK, PHRASE_INDEX_MAKE_TOKEN(14, null_token));
+    pinyin_mask_out(context, PHRASE_INDEX_LIBRARY_MASK, PHRASE_INDEX_MAKE_TOKEN(NETWORK_DICTIONARY, null_token));
 
-    import_iterator_t* iter = pinyin_begin_add_phrases(context, 14);
+    import_iterator_t* iter = pinyin_begin_add_phrases(context, NETWORK_DICTIONARY);
     if (iter == NULL) {
         return;
     }
