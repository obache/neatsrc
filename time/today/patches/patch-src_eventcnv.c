$NetBSD$

--- src/eventcnv.c.orig	2015-08-24 08:24:18.000000000 +0000
+++ src/eventcnv.c
@@ -17,7 +17,7 @@
 #include <ctype.h>
 #include <errno.h>
 
-#ifdef linux
+#if defined(unix)
 #define strnicmp	strncasecmp
 #endif
 
