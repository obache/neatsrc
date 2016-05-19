$NetBSD$

--- base/base.gyp.orig	2016-01-10 19:41:41.000000000 +0000
+++ base/base.gyp
@@ -145,12 +145,12 @@
             },
           },
         }],
-        ['target_platform=="Linux" and server_dir!=""', {
+        ['(target_platform=="Linux" or target_platform=="NetBSD") and server_dir!=""', {
           'defines': [
             'MOZC_SERVER_DIRECTORY="<(server_dir)"',
           ],
         }],
-        ['target_platform=="Linux" and document_dir!=""', {
+        ['(target_platform=="Linux" or target_platform=="NetBSD") and document_dir!=""', {
           'defines': [
             'MOZC_DOCUMENT_DIRECTORY="<(document_dir)"',
           ],
