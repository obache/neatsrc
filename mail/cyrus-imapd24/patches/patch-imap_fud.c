$NetBSD$

* try to use LOGIN_NAME_MAX in <limits.h> for failback vaule of MAXLOGNAME
* avoid rerefine MAXLOGNAME may be in sys/param.h

--- imap/fud.c.orig	2020-08-19 00:54:54.000000000 +0000
+++ imap/fud.c
@@ -62,6 +62,7 @@
 #include <netdb.h>
 #include <errno.h>
 #include <pwd.h>
+#include <limits.h>
 
 #include "acl.h"
 #include "assert.h"
@@ -102,7 +103,13 @@ int soc = 0; /* inetd (master) has hande
 
 char who[16];
 
+#ifndef MAXLOGNAME
+#  ifdef LOGIN_NAME_MAX
+#define MAXLOGNAME (LOGIN_NAME_MAX - 1)
+#  else
 #define MAXLOGNAME 16		/* should find out for real */
+#  endif
+#endif
 #define MAXDOMNAME 20		/* should find out for real */
 
 int begin_handling(void)
