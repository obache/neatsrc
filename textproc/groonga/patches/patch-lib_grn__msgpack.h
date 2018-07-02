$NetBSD$

* Suppress a waring with -fstack-protector

--- lib/grn_msgpack.h.orig	2018-06-25 02:46:51.000000000 +0000
+++ lib/grn_msgpack.h
@@ -21,9 +21,16 @@
 #include "grn.h"
 
 #ifdef GRN_WITH_MESSAGE_PACK
-# define memcpy(dest, src, n) grn_memcpy(dest, src, n)
+# ifdef memcpy
+#  define GRN_WITH_CUSTOM_MEMCPY
+# endif /* memcpy */
+# ifndef GRN_WITH_CUSTOM_MEMCPY
+#  define memcpy(dest, src, n) grn_memcpy(dest, src, n)
+# endif /* GRN_WITH_CUSTOM_MEMCPY */
 # include <msgpack.h>
-# undef memcpy
+# ifdef GRN_WITH_CUSTOM_MEMCPY
+#  undef memcpy
+# endif /* GRN_WITH_CUSTOM_MEMCPY */
 
 # if MSGPACK_VERSION_MAJOR < 1
 typedef unsigned int msgpack_size_t;
