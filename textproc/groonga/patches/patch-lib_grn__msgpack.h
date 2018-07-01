$NetBSD$

* only required for Windows

--- lib/grn_msgpack.h.orig	2018-06-25 02:46:51.000000000 +0000
+++ lib/grn_msgpack.h
@@ -21,9 +21,13 @@
 #include "grn.h"
 
 #ifdef GRN_WITH_MESSAGE_PACK
+# ifdef WIN32
 # define memcpy(dest, src, n) grn_memcpy(dest, src, n)
+# endif
 # include <msgpack.h>
+# ifdef WIN32
 # undef memcpy
+# endif
 
 # if MSGPACK_VERSION_MAJOR < 1
 typedef unsigned int msgpack_size_t;
