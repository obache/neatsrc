$NetBSD$

* fix insufficient struct member initialization

--- src/scim_anthy_prefs.cpp.orig	2016-06-18 15:55:04.000000000 +0000
+++ src/scim_anthy_prefs.cpp
@@ -242,8 +242,8 @@ BoolConfigData config_bool_common [] =
     },
     {
         NULL,
-        "",
-        "",
+        false,
+        false,
         NULL,
         NULL,
         NULL,
