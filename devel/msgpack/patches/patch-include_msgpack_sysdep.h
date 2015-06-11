$NetBSD$

* NetBSD support
* Fixes endian detection

--- include/msgpack/sysdep.h.orig	2015-03-04 13:40:13.000000000 +0000
+++ include/msgpack/sysdep.h
@@ -47,6 +47,11 @@ typedef unsigned __int64 uint64_t;
 typedef long _msgpack_atomic_counter_t;
 #define _msgpack_sync_decr_and_fetch(ptr) InterlockedDecrement(ptr)
 #define _msgpack_sync_incr_and_fetch(ptr) InterlockedIncrement(ptr)
+#elif defined(__NetBSD__)
+#define _msgpack_atomic_counter_header <sys/atomic.h>
+typedef unsigned int _msgpack_atomic_counter_t;
+#define _msgpack_sync_decr_and_fetch(ptr) atomic_dec_uint_nv(ptr)
+#define _msgpack_sync_incr_and_fetch(ptr) atomic_inc_uint_nv(ptr)
 #elif defined(__GNUC__) && ((__GNUC__*10 + __GNUC_MINOR__) < 41)
 
 #if defined(__cplusplus)
@@ -75,19 +80,42 @@ typedef unsigned int _msgpack_atomic_cou
 
 #else
 
-#include <arpa/inet.h>  /* __BYTE_ORDER */
-#  if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__OpenBSD__) && \
-       !(defined(__sun) && defined(__SVR4))
+#include <arpa/inet.h>
+#if defined(linux) || defined(__GLIBC__)
+#    include <endian.h>
 #    include <byteswap.h>
+#elif defined(CSRG_BASED)
+#  if defined(__NetBSD__) || defined(__OpenBSD__)
+#    include <sys/types.h>
+#  endif
+#  if defined(__NetBSD__)
+#    include <machine/bswap.h>
 #  endif
+#    include <sys/endian.h>
+#endif
 
 #endif
 
 #if !defined(__LITTLE_ENDIAN__) && !defined(__BIG_ENDIAN__)
+#if defined(__BYTE_ORDER)
 #if __BYTE_ORDER == __LITTLE_ENDIAN
 #define __LITTLE_ENDIAN__
 #elif __BYTE_ORDER == __BIG_ENDIAN
 #define __BIG_ENDIAN__
+#endif
+#elif defined(BYTE_ORDER)
+#if BYTE_ORDER == LITTLE_ENDIAN
+#define __LITTLE_ENDIAN__
+#elif BYTE_ORDER == LITTLE_ENDIAN
+#define __BIG_ENDIAN__
+#endif
+#elif defined(sun) && defined(SVR4)
+#include <sys/isa_defs.h>
+#if defined(_LITTLE_ENDIAN)
+#define __LITTLE_ENDIAN__
+#elif defined(_BIG_ENDIAN)
+#define __BIG_ENDIAN__
+#endif
 #elif _WIN32
 #define __LITTLE_ENDIAN__
 #endif
@@ -132,6 +160,8 @@ typedef unsigned int _msgpack_atomic_cou
 #  define _msgpack_be64(x) bswap_64(x)
 #elif defined(__DARWIN_OSSwapInt64)
 #  define _msgpack_be64(x) __DARWIN_OSSwapInt64(x)
+#elif defined(bswap64)
+#  define _msgpack_be64(x) bswap64(x)
 #else
 #define _msgpack_be64(x) \
     ( ((((uint64_t)x) << 56)                         ) | \
