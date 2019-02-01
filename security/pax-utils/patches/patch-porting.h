$NetBSD$

* same condition as used

--- porting.h.orig	2019-01-14 22:35:29.000000000 +0000
+++ porting.h
@@ -61,7 +61,7 @@
 # include <machine/endian.h>
 #endif
 
-#if defined(__GLIBC__) || defined(__UCLIBC__)
+#if defined(__GLIBC__) || defined(__UCLIBC__) || defined(__NetBSD__)
 # include <glob.h>
 #endif
 
