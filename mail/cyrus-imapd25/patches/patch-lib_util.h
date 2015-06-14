$NetBSD$

--- lib/util.h.orig	2015-05-08 03:49:52.000000000 +0000
+++ lib/util.h
@@ -66,7 +66,7 @@
 # endif /* HAVE_PCREPOSIX_H */
 #endif /* ENABLE_REGEX */
 
-#ifndef __GNUC__
+#if !defined(__GNUC__) || defined(__NetBSD__)
 typedef int (*__compar_fn_t)(const void *, const void *);
 #endif
 
