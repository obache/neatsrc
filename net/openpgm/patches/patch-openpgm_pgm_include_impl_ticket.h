$NetBSD$

* NetBSD atomic_ops support

--- openpgm/pgm/include/impl/ticket.h.orig	2012-12-04 02:57:19.000000000 +0000
+++ openpgm/pgm/include/impl/ticket.h
@@ -38,6 +38,8 @@ typedef union pgm_ticket_t pgm_ticket_t;
 #	include <atomic.h>
 #elif defined( __APPLE__ )
 #	include <libkern/OSAtomic.h>
+#elif defined( __NetBSD__ )
+#	include <sys/atomic.h>
 #elif defined( _WIN32 )
 #	define VC_EXTRALEAN
 #	define WIN32_LEAN_AND_MEAN
@@ -128,8 +130,8 @@ pgm_atomic_compare_and_exchange32 (
 			: "r" (newval),  "a" (oldval)
 			: "memory", "cc"  );
 	return (bool)result;
-#elif defined( __sun )
-/* Solaris intrinsic */
+#elif defined( __sun ) || defined( _NetBSD__ )
+/* Solaris and NetBSD intrinsic */
 	const uint32_t original = atomic_cas_32 (atomic, oldval, newval);
 	return (oldval == original);
 #elif defined( __APPLE__ )
