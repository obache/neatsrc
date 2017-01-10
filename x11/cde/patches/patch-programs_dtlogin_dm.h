$NetBSD$

--- programs/dtlogin/dm.h.orig	2015-05-09 23:09:11.000000000 +0000
+++ programs/dtlogin/dm.h
@@ -202,7 +202,7 @@
  ***************************************************************************/
 
 /*#if defined(SYSV) && !defined(hpux)*/
-#if defined(SYSV) || defined(SVR4) || defined(linux) || defined(__FreeBSD__) || defined(OpenBSD)
+#if defined(SYSV) || defined(SVR4) || defined(linux) || defined(CSRG_BASED)
 #   include	<sys/wait.h>
 # define waitCode(w)	WEXITSTATUS(w)
 # define waitSig(w)	WTERMSIG(w)
