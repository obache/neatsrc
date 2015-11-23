$NetBSD$

* NetBSD support

--- include/msgpack/sysdep.h.orig	2015-11-22 07:26:58.000000000 +0000
+++ include/msgpack/sysdep.h
@@ -43,6 +43,11 @@
     typedef long _msgpack_atomic_counter_t;
 #   define _msgpack_sync_decr_and_fetch(ptr) InterlockedDecrement(ptr)
 #   define _msgpack_sync_incr_and_fetch(ptr) InterlockedIncrement(ptr)
+#elif defined(__NetBSD__)
+#   define _msgpack_atomic_counter_header <sys/atomic.h>
+    typedef unsigned int _msgpack_atomic_counter_t;
+#   define _msgpack_sync_decr_and_fetch(ptr) atomic_dec_uint_nv(ptr)
+#   define _msgpack_sync_incr_and_fetch(ptr) atomic_inc_uint_nv(ptr)
 #elif defined(__GNUC__) && ((__GNUC__*10 + __GNUC_MINOR__) < 41)
 
 #   if defined(__cplusplus)
@@ -75,6 +80,10 @@
 #   if defined(linux)
 #       include <byteswap.h>
 #   endif
+#   if defined(__NetBSD__)
+#       include <sys/types.h>
+#       include <machine/bswap.h>
+#   endif
 
 #endif
 
@@ -116,6 +125,8 @@
 #        define _msgpack_be64(x) bswap_64(x)
 #   elif defined(__DARWIN_OSSwapInt64)
 #        define _msgpack_be64(x) __DARWIN_OSSwapInt64(x)
+#   elif defined(bswap64)
+#        define _msgpack_be64(x) bswap64(x)
 #   else
 #        define _msgpack_be64(x) \
              ( ((((uint64_t)x) << 56)                         ) | \
