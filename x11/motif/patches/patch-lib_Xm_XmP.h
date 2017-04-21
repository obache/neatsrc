$NetBSD: patch-lib_Xm_XmP.h,v 1.1 2013/09/08 07:23:56 ryoon Exp $

* Fix build under OS X 10.8.4 with clang.
  http://bugs.motifzone.net/show_bug.cgi?id=1625

--- lib/Xm/XmP.h.orig	2017-03-27 22:24:31.000000000 +0000
+++ lib/Xm/XmP.h
@@ -1437,9 +1437,13 @@ extern void _XmDestroyParentCallback( 
 
 #endif /* NO_XM_1_2_BC */
 
-#if __GNUC__
+#ifdef __GNUC__
 #  define XM_DEPRECATED  __attribute__((__deprecated__))
+# ifndef __APPLE__
 #  define XM_ALIAS(sym)  __attribute__((__weak__,alias(#sym)))
+# else
+#  define XM_ALIAS(sym)
+# endif
 #else
 #  define XM_DEPRECATED
 #  define XM_ALIAS(sym)
