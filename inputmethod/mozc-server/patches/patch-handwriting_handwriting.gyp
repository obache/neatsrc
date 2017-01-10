$NetBSD: patch-handwriting_handwriting.gyp,v 1.3 2014/01/19 01:18:50 ryoon Exp $

--- handwriting/handwriting.gyp.orig	2016-01-10 19:41:41.000000000 +0000
+++ handwriting/handwriting.gyp
@@ -29,7 +29,7 @@
 
 {
   'variables': {
-    'zinnia_model_file%': '/usr/share/tegaki/models/zinnia/handwriting-ja.model',
+    'zinnia_model_file%': '@PREFIX@/share/tegaki/models/zinnia/handwriting-ja.model',
   },
   'targets': [
     {
