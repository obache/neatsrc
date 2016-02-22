$NetBSD$

* NetBSD atomic_ops support

--- openpgm/pgm/include/pgm/atomic.h.orig	2012-12-04 02:57:20.000000000 +0000
+++ openpgm/pgm/include/pgm/atomic.h
@@ -29,6 +29,8 @@
 #	include <atomic.h>
 #elif defined( __APPLE__ )
 #	include <libkern/OSAtomic.h>
+#elif defined( __NetBSD__ )
+#	include <sys/atomic.h>
 #elif defined( _MSC_VER )
 /* not implemented in MinGW */
 #	include <intrin.h>
@@ -62,8 +64,8 @@ pgm_atomic_exchange_and_add32 (
 	__asm__ volatile ("lock; xaddl %0, %1"
 		       :: "r" (result), "m" (*atomic)  );
 	return result;
-#elif defined( __sun )
-/* Solaris intrinsic */
+#elif defined( __sun ) || defined(__NetBSD__)
+/* Solaris and NetBSD intrinsic */
 	const uint32_t nv = atomic_add_32_nv (atomic, (int32_t)val);
 	return nv - val;
 #elif defined( __APPLE__ )
@@ -101,7 +103,7 @@ pgm_atomic_add32 (
 #elif (defined( __SUNPRO_C ) || defined( __SUNPRO_CC )) && (defined( __i386 ) || defined( __amd64 ))
 	__asm__ volatile ("lock; addl %1, %0"
 		       :: "r" (val), "m" (*atomic)  );
-#elif defined( __sun )
+#elif defined( __sun ) || defined( __NetBSD__ )
 	atomic_add_32 (atomic, (int32_t)val);
 #elif defined( __APPLE__ )
 	OSAtomicAdd32Barrier ((int32_t)val, (volatile int32_t*)atomic);
@@ -132,7 +134,7 @@ pgm_atomic_inc32 (
 #elif (defined( __SUNPRO_C ) || defined( __SUNPRO_CC )) && (defined( __i386 ) || defined( __amd64 ))
 	__asm__ volatile ("lock; incl %0"
 		       :: "m" (*atomic)  );
-#elif defined( __sun )
+#elif defined( __sun ) || defined( __NetBSD__ )
 	atomic_inc_32 (atomic);
 #elif defined( __APPLE__ )
 	OSAtomicIncrement32Barrier ((volatile int32_t*)atomic);
@@ -163,7 +165,7 @@ pgm_atomic_dec32 (
 	__asm__ volatile ("lock\n\t"
 			  "decl %0"
 		       :: "m" (*atomic)  );
-#elif defined( __sun )
+#elif defined( __sun ) || defined( __NetBSD__ )
 	atomic_dec_32 (atomic);
 #elif defined( __APPLE__ )
 	OSAtomicDecrement32Barrier ((volatile int32_t*)atomic);
