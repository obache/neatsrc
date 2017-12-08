$NetBSD$

* Fix iconv(3) usage
  https://github.com/BoGoEngine/fcitx-bogo/pull/22

--- src/bogo-im.c.orig	2014-08-10 06:36:29.000000000 +0000
+++ src/bogo-im.c
@@ -616,7 +616,7 @@ int Utf32ToUtf8Char(const uint32_t c, ch
     str[0] = c;
     str[1] = 0;
     
-    iconv_t *conv;
+    iconv_t conv;
     
     union {
         short s;
@@ -644,7 +644,7 @@ int Utf32ToUtf8Char(const uint32_t c, ch
 
 uint32_t Utf8ToUtf32Char(char *src)
 {
-    iconv_t *conv;
+    iconv_t conv;
 
     union {
         short s;
@@ -661,9 +661,9 @@ uint32_t Utf8ToUtf32Char(char *src)
     
     size_t inLength = UTF8_MAX_LENGTH + 1;
     size_t outLength = sizeof(uint32_t);
-    IconvStr buff = (IconvStr) output;
+    char* buff = (char*) output;
 
-    iconv(conv, &src, &inLength, &buff, &outLength);
+    iconv(conv, (IconvStr*)&src, &inLength, &buff, &outLength);
     
     iconv_close(conv);
     return output[0];
