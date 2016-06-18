$NetBSD$

* fix insufficient struct member initialization

--- src/scim_anthy_prefs.cpp.orig	2008-04-24 03:49:53.000000000 +0000
+++ src/scim_anthy_prefs.cpp
@@ -95,6 +95,7 @@ BoolConfigData config_bool_common [] =
         N_("A_llow spliting romaji on editing preedit string"),
         NULL,
         N_("If this check is enabled, you can delete each letter."),
+        NULL,
         false,
     },
     {
@@ -104,6 +105,7 @@ BoolConfigData config_bool_common [] =
         N_("_Entering the pseudo ASCII input mode with capital letters."),
         NULL,
         N_("If this check is enabled, capital letters will becomes a trigger to enter the pseudo ASCII input mode."),
+		NULL,
         false,
     },
     {
@@ -113,6 +115,7 @@ BoolConfigData config_bool_common [] =
         N_("Insert a _blank with a blank key."),
         NULL,
         N_("If this check is enabled, a blank key will works to insert a blank when entering the pseudo ASCII input mode."),
+		NULL,
         false,
     },
     {
@@ -122,6 +125,7 @@ BoolConfigData config_bool_common [] =
         N_("_Show predicted candidates while inputting letters"),
         NULL,
         NULL,
+        NULL,
         false,
     },
     {
@@ -131,6 +135,7 @@ BoolConfigData config_bool_common [] =
         N_("Use _direct select keys while predicting"),
         NULL,
         NULL,
+		NULL,
         false,
     },
     {
@@ -215,8 +220,8 @@ BoolConfigData config_bool_common [] =
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
@@ -273,6 +278,7 @@ IntConfigData config_int_common [] =
         NULL,
         NULL,
         NULL,
+		NULL,
         false,
     },
 };
