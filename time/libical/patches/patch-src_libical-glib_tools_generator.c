$NetBSD$

* fix ctype(3) usage

--- src/libical-glib/tools/generator.c.orig	2021-04-17 13:12:32.000000000 +0000
+++ src/libical-glib/tools/generator.c
@@ -199,12 +199,12 @@ gchar *get_upper_camel_from_lower_snake(
 
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
@@ -238,7 +238,7 @@ gchar *get_upper_snake_from_lower_snake(
             ret[i] = '_';
             ret[i + 1] = '\0';
         } else {
-            ret[i] = toupper(lowerSnake[i]);
+            ret[i] = toupper((unsigned char)lowerSnake[i]);
             ret[i + 1] = '\0';
         }
     }
@@ -277,14 +277,14 @@ gchar *get_lower_snake_from_upper_camel(
     *buffer = '\0';
 
     for (i = 0; i < (guint)strlen(upperCamel); i++) {
-        if (isupper((int)upperCamel[i]) && i != 0) {
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
