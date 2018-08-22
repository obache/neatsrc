$NetBSD: patch-lib_Xm_XmP.h,v 1.1 2013/09/08 07:23:56 ryoon Exp $

* Fix build under OS X 10.8.4 with clang.
  http://bugs.motifzone.net/show_bug.cgi?id=1625

--- lib/Xm/XmP.h.orig	2017-08-28 02:33:10.000000000 +0000
+++ lib/Xm/XmP.h
@@ -1437,7 +1437,7 @@ extern void _XmDestroyParentCallback( 
 
 #endif /* NO_XM_1_2_BC */
 
-#if __GNUC__
+#ifdef __GNUC__
 #  define XM_DEPRECATED  __attribute__((__deprecated__))
 #  ifdef NO_WEAK_ALIASES
 #    define XM_ALIAS(sym)
