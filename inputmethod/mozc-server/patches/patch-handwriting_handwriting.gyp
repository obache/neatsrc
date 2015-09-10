$NetBSD: patch-handwriting_handwriting.gyp,v 1.3 2014/01/19 01:18:50 ryoon Exp $

--- handwriting/handwriting.gyp.orig	2015-06-07 07:16:23.000000000 +0000
+++ handwriting/handwriting.gyp
@@ -29,7 +29,7 @@
 
 {
   'variables': {
-    'zinnia_model_file%': '/usr/share/tegaki/models/zinnia/handwriting-ja.model',
+    'zinnia_model_file%': '@PREFIX@/share/tegaki/models/zinnia/handwriting-ja.model',
   },
   'targets': [
     {
@@ -43,12 +43,12 @@
         'zinnia.gyp:zinnia',
       ],
       'conditions': [
-        ['target_platform=="Linux" and use_libzinnia==1', {
+        ['(target_platform=="Linux" or target_platform=="NetBSD") and use_libzinnia==1', {
           'defines': [
             'USE_LIBZINNIA',
           ],
         }],
-        ['target_platform=="Linux" and use_libzinnia==1 and zinnia_model_file!=""', {
+        ['(target_platform=="Linux" or target_platform=="NetBSD") and use_libzinnia==1 and zinnia_model_file!=""', {
           'defines': [
             'MOZC_ZINNIA_MODEL_FILE="<(zinnia_model_file)"',
           ],
