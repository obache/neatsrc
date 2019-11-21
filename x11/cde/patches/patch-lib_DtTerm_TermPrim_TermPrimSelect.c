$NetBSD$

--- lib/DtTerm/TermPrim/TermPrimSelect.c.orig	2019-10-12 21:43:45.000000000 +0000
+++ lib/DtTerm/TermPrim/TermPrimSelect.c
@@ -47,7 +47,7 @@
 #include <Xm/DropSMgr.h>
 #include <Xm/DropTrans.h>
 
-#if defined(OPENBSD_ARCHITECTURE)
+#if defined(OPENBSD_ARCHITECTURE) || defined(__NetBSD__)
 #include <ctype.h>
 #include <wctype.h>
 #endif
