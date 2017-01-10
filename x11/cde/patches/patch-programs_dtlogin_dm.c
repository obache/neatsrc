$NetBSD$

--- programs/dtlogin/dm.c.orig	2015-05-09 23:09:11.000000000 +0000
+++ programs/dtlogin/dm.c
@@ -62,7 +62,7 @@
 # include	<time.h>
 # include	<utime.h>
 # include	<pwd.h>
-#if defined(linux) || defined(__FreeBSD__) || defined(__NetBSD__) || \
+#if defined(linux) || defined(CSRG_BASED) || \
     defined(sun)
 # include	<stdarg.h>
 #else
