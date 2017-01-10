$NetBSD$

* Segmentation fault with gcc-4.1.3 on NetBSD-5.1.

--- lib/mkmf-gnome2.rb.orig	2016-01-27 05:22:29.000000000 +0000
+++ lib/mkmf-gnome2.rb
@@ -77,7 +77,8 @@ try_compiler_option '-Winit-self'
 try_compiler_option '-Wlarger-than-65500'
 try_compiler_option '-Wmissing-declarations'
 try_compiler_option '-Wmissing-format-attribute'
-try_compiler_option '-Wmissing-include-dirs'
+# NOTE: This generates segmentation fault with gcc-4.1.3 on NetBSD-5.1
+# try_compiler_option '-Wmissing-include-dirs'
 try_compiler_option '-Wmissing-noreturn'
 try_compiler_option '-Wmissing-prototypes'
 try_compiler_option '-Wnested-externs'
