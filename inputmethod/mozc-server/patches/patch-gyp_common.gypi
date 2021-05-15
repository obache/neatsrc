$NetBSD: patch-gyp_common.gypi,v 1.12 2021/02/27 19:13:26 ryoon Exp $

* NetBSD support

--- gyp/common.gypi.orig	2021-02-15 05:04:33.000000000 +0000
+++ gyp/common.gypi
@@ -93,6 +93,14 @@
       '-fstack-protector',
       '--param=ssp-buffer-size=4',
     ],
+    # netbsd_cflags will be used for NetBSD.
+    'netbsd_cflags': [
+      '<@(gcc_cflags)',
+      '-fPIC',
+      '-D_NETBSD_SOURCE',
+      '-fno-exceptions',
+      '<!(echo $CFLAGS)',
+    ],
     # mac_cflags will be used in Mac.
     # Xcode 4.5 which we are currently using does not support ssp-buffer-size.
     # TODO(horo): When we can use Xcode 4.6 which supports ssp-buffer-size,
@@ -318,6 +332,24 @@
           }],
         ],
       }],
+      ['OS=="netbsd"', {
+        'defines': [
+          'OS_NETBSD',
+        ],
+        'cflags': [
+          '<@(netbsd_cflags)',
+          '-fPIC',
+          '-fno-exceptions',
+        ],
+        'cflags_cc': [
+          # We use deprecated <hash_map> and <hash_set> instead of upcoming
+          # <unordered_map> and <unordered_set>.
+          '-Wno-deprecated',
+        ],
+        'ldflags': [
+          '-pthread',
+        ],
+      }],
       ['OS=="mac"', {
         'defines': [
           '__APPLE__',
