$NetBSD$

--- lib/include/vm_basic_types.h.orig	2015-10-21 19:01:53.000000000 +0000
+++ lib/include/vm_basic_types.h
@@ -79,7 +79,7 @@
 
 /* STRICT ANSI means the Xserver build and X defines Bool differently. */
 #if !defined(_XTYPEDEF_BOOL) && \
-    (!defined(__STRICT_ANSI__) || defined(__FreeBSD__) || defined(__MINGW32__))
+    (!defined(__STRICT_ANSI__) || defined(__FreeBSD__) || defined(__MINGW32__) || defined(__NetBSD__))
 #define _XTYPEDEF_BOOL
 typedef char           Bool;
 #endif
