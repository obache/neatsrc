$NetBSD$

--- imap/fud.c.orig	2020-08-24 03:32:43.000000000 +0000
+++ imap/fud.c
@@ -60,6 +60,7 @@
 #include <netdb.h>
 #include <errno.h>
 #include <pwd.h>
+#include <limits.h>
 
 #include "acl.h"
 #include "mboxlist.h"
@@ -96,8 +97,14 @@ static void send_reply(struct sockaddr *
 
 static int soc = 0; /* inetd (master) has handed us the port as stdin */
 
-#ifndef MAXDOMNAME
+#ifndef MAXLOGNAME
+#  ifdef LOGIN_NAME_MAX
+#define MAXLOGNAME (LOGIN_NAME_MAX - 1)
+#  else
 #define MAXLOGNAME 16           /* should find out for real */
+#  endif
+#endif
+#ifndef MAXDOMNAME
 #define MAXDOMNAME 20           /* should find out for real */
 #endif
 
