$NetBSD: patch-fep_uim-fep.c,v 1.1 2019/11/01 16:21:11 nia Exp $

Include missing header for tcgetattr

--- fep/uim-fep.c.orig	2017-08-14 00:07:26.000000000 +0000
+++ fep/uim-fep.c
@@ -108,6 +108,9 @@
 #ifdef HAVE_LIBUTIL_H
 #include <libutil.h>
 #endif
+#ifdef HAVE_TERMIOS_H
+#include <termios.h>
+#endif
 
 #include <uim/uim.h>
 
