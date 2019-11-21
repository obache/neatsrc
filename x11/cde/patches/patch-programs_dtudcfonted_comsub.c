$NetBSD$

* fix signal handler signature

--- programs/dtudcfonted/comsub.c.orig	2019-10-12 21:43:45.000000000 +0000
+++ programs/dtudcfonted/comsub.c
@@ -44,7 +44,7 @@
 #include "ufontrsrc.h"
 
 static void writePtn(char *ptn, int width, int height, FILE *fp);
-static void sig_receive(void);
+static void sig_receive(int);
 char	*get_cmd_path(char *path, char *cmd) ;
 
 extern Resource resource;
@@ -1522,7 +1522,7 @@ int		*err)		/* errors : 			*/
  */
 
 static void
-sig_receive(void)
+sig_receive(int sig)
 {
     sig_flg = 1;
     return;
