$NetBSD$

--- session/session_base.gyp.orig	2015-06-07 07:16:23.000000000 +0000
+++ session/session_base.gyp
@@ -101,6 +101,7 @@
         '../composer/composer.gyp:key_event_util',
         '../composer/composer.gyp:key_parser',
         '../config/config.gyp:config_handler',
+        '../protocol/protocol.gyp:commands_proto',
         '../protocol/protocol.gyp:config_proto',
         'keymap',
       ],
