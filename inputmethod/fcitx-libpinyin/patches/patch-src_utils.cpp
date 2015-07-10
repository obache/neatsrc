$NetBSD$

* no matter libpinyin tools found or not, we can build it

--- src/utils.cpp.orig	2013-07-15 20:34:05.000000000 +0000
+++ src/utils.cpp
@@ -6,13 +6,16 @@
 char* FcitxLibPinyinGetSysPath(LIBPINYIN_LANGUAGE_TYPE type)
 {
     char* syspath = NULL;
+#ifdef LIBPINYIN_TOOLS_FOUND
     if (type == LPLT_Simplified) {
+#endif
         /* portable detect here */
         if (getenv("FCITXDIR")) {
             syspath = fcitx_utils_get_fcitx_path_with_filename("datadir", "libpinyin/data");
         } else {
             syspath = strdup(LIBPINYIN_PKGDATADIR "/data");
         }
+#ifdef LIBPINYIN_TOOLS_FOUND
     }
     else {
         /* portable detect here */
@@ -22,6 +25,7 @@ char* FcitxLibPinyinGetSysPath(LIBPINYIN
             syspath = strdup(FCITX_LIBPINYIN_ZHUYIN_DATADIR);
         }
     }
+#endif
     return syspath;
 }
 
@@ -29,11 +33,14 @@ char* FcitxLibPinyinGetSysPath(LIBPINYIN
 char* FcitxLibPinyinGetUserPath(LIBPINYIN_LANGUAGE_TYPE type)
 {
     char* user_path = NULL;
+#ifdef LIBPINYIN_TOOLS_FOUND
     if (type == LPLT_Simplified) {
+#endif
         FILE* fp = FcitxXDGGetFileUserWithPrefix("libpinyin", "data/.place_holder", "w", NULL);
         if (fp)
             fclose(fp);
         FcitxXDGGetFileUserWithPrefix("libpinyin", "data", NULL, &user_path);
+#ifdef LIBPINYIN_TOOLS_FOUND
     }
     else {
         FILE* fp = FcitxXDGGetFileUserWithPrefix("libpinyin", "zhuyin_data/.place_holder", "w", NULL);
@@ -41,5 +48,6 @@ char* FcitxLibPinyinGetUserPath(LIBPINYI
             fclose(fp);
         FcitxXDGGetFileUserWithPrefix("libpinyin", "zhuyin_data", NULL, &user_path);
     }
+#endif
     return user_path;
 }
