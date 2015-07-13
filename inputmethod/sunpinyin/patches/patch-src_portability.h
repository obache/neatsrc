$NetBSD$

* NetBSD too

--- src/portability.h.orig	2011-02-18 03:39:52.000000000 +0000
+++ src/portability.h
@@ -71,7 +71,7 @@
 inline double log2(double x) { return log(x) / M_LN2; }
 #endif
 
-#if defined(sun) // Solaris/HP-UX 's iconv is const char**
+#if defined(sun) || defined(__NetBSD__)// Solaris/HP-UX/NetBSD 's iconv is const char**
 typedef const char* TIConvSrcPtr;
 #else
 typedef char* TIConvSrcPtr;
