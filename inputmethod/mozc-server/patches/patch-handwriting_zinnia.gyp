$NetBSD: patch-handwriting_zinnia.gyp,v 1.1 2014/01/19 01:18:50 ryoon Exp $

--- handwriting/zinnia.gyp.orig	2016-01-10 19:41:41.000000000 +0000
+++ handwriting/zinnia.gyp
@@ -80,7 +80,7 @@
                 'VERSION="0.06"',
               ],
             }],
-            ['target_platform=="Linux" or target_platform=="Mac"', {
+            ['target_platform=="Linux" or target_platform=="Mac" or target_platform=="NetBSD"', {
               'defines': [
                 'HAVE_CONFIG_H=1'
               ],
