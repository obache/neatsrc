$NetBSD$

--- lib/DtTerm/TermPrim/TermPrimSetPty.c.orig	2019-10-12 21:43:45.000000000 +0000
+++ lib/DtTerm/TermPrim/TermPrimSetPty.c
@@ -65,7 +65,7 @@
 #include <sys/stat.h>
 #endif	/* USE_TIOCCONS */
 
-#if defined(LINUX_ARCHITECTURE) || defined(OPENBSD_ARCHITECTURE)
+#if defined(LINUX_ARCHITECTURE) || defined(OPENBSD_ARCHITECTURE) || defined(__NetBSD__)
 #include <sys/ioctl.h>
 #endif /* LINUX_ARCHITECTURE */
 
