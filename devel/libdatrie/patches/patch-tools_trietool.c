$NetBSD$

* fix ctype(3) usage

--- tools/trietool.c.orig	2018-06-06 08:39:34.000000000 +0000
+++ tools/trietool.c
@@ -405,7 +405,7 @@ command_add_list (int argc, char *argv[]
             /* mark key ending and find data begin */
             if ('\0' != *data) {
                 *data++ = '\0';
-                while (isspace (*data))
+                while (isspace ((unsigned char)*data))
                     ++data;
             }
             /* decode data */
@@ -614,12 +614,12 @@ string_trim (char *s)
     char   *p;
 
     /* skip leading white spaces */
-    while (*s && isspace (*s))
+    while (*s && isspace ((unsigned char)*s))
         ++s;
 
     /* trim trailing white spaces */
     p = s + strlen (s) - 1;
-    while (isspace (*p))
+    while (isspace ((unsigned char)*p))
         --p;
     *++p = '\0';
 
