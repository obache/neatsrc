$NetBSD$

* fix ctype(3) usage

--- src/libical-glib/tools/generator.c.orig	2018-08-14 19:49:51.000000000 +0000
+++ src/libical-glib/tools/generator.c
@@ -200,12 +200,12 @@ gchar *get_upper_camel_from_lower_snake(
 
     buffer = g_new(gchar, BUFFER_SIZE);
     memset(buffer, 0, BUFFER_SIZE);
-    buffer[0] = toupper(lowerSnake[0]);
+    buffer[0] = toupper((unsigned char)lowerSnake[0]);
     buffer[1] = '\0';
     for (i = 1; i < (guint)strlen(lowerSnake); i++) {
         if (lowerSnake[i] == '_') {
             len = (guint)strlen(buffer);
-            buffer[len] = toupper(lowerSnake[++i]);
+            buffer[len] = toupper((unsigned char)lowerSnake[++i]);
             buffer[len + 1] = '\0';
         } else {
             len = (guint)strlen(buffer);
@@ -239,7 +239,7 @@ gchar *get_upper_snake_from_lower_snake(
             ret[i] = '_';
             ret[i + 1] = '\0';
         } else {
-            ret[i] = toupper(lowerSnake[i]);
+            ret[i] = toupper((unsigned char)lowerSnake[i]);
             ret[i + 1] = '\0';
         }
     }
@@ -278,14 +278,14 @@ gchar *get_lower_snake_from_upper_camel(
     *buffer = '\0';
 
     for (i = 0; i < (guint)strlen(upperCamel); i++) {
-        if (isupper(upperCamel[i]) && i != 0) {
+        if (isupper((unsigned char)upperCamel[i]) && i != 0) {
             len = (guint)strlen(buffer);
             buffer[len] = '_';
-            buffer[len + 1] = tolower(upperCamel[i]);
+            buffer[len + 1] = tolower((unsigned char)upperCamel[i]);
             buffer[len + 2] = '\0';
         } else {
             len = (guint)strlen(buffer);
-            buffer[len] = tolower(upperCamel[i]);
+            buffer[len] = tolower((unsigned char)upperCamel[i]);
             buffer[len + 1] = '\0';
         }
     }
