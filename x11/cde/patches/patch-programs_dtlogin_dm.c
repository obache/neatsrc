$NetBSD$

* use <signal.h> for signals
* use utmpx on NetBSD too

--- programs/dtlogin/dm.c.orig	2019-10-12 21:43:45.000000000 +0000
+++ programs/dtlogin/dm.c
@@ -52,9 +52,9 @@
  */
 
 # include	<sys/types.h>
-# include	<sys/signal.h>
+# include	<signal.h>
 # include	<sys/stat.h>
-#if defined(__FreeBSD__) && OSMAJORVERSION > 8
+#if defined(__FreeBSD__) && OSMAJORVERSION > 8 || defined(__NetBSD__)
 # include	<utmpx.h>
 #else
 # include	<utmp.h>
@@ -1689,7 +1689,7 @@ GettyMessage( struct display *d, int msg
 int 
 GettyRunning( struct display *d )
 {
-#if defined(__FreeBSD__) && OSMAJORVERSION > 8
+#if defined(__FreeBSD__) && OSMAJORVERSION > 8 || defined(__NetBSD__)
     struct utmpx utmp;		/* local struct for new entry		   */
     struct utmpx *u;		/* pointer to entry in utmp file	   */
 #else
@@ -1714,7 +1714,7 @@ GettyRunning( struct display *d )
         return FALSE;
 
 
-#if defined(__FreeBSD__) && OSMAJORVERSION > 8
+#if defined(__FreeBSD__) && OSMAJORVERSION > 8 || defined(__NetBSD__)
     bzero(&utmp, sizeof(struct utmpx));
 #else
     bzero(&utmp, sizeof(struct utmp));
