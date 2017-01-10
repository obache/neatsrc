$NetBSD$

* resolve deprecated conversion from string constant to "char*"

--- src/scim_anthy_helper.cpp.orig	2016-06-18 15:55:04.000000000 +0000
+++ src/scim_anthy_helper.cpp
@@ -406,8 +406,8 @@ run (const String &display, const Config
     char **argv = new char * [4];
     int    argc = 3;
 
-    argv [0] = "anthy-imengine-helper";
-    argv [1] = "--display";
+    argv [0] = const_cast<char *> ("anthy-imengine-helper");
+    argv [1] = const_cast<char *> ("--display");
     argv [2] = const_cast<char *> (display.c_str ());
     argv [3] = 0;
  
