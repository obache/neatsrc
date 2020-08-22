$NetBSD$

--- imap/fud.c.orig	2020-08-19 03:59:50.000000000 +0000
+++ imap/fud.c
@@ -59,6 +59,7 @@
 #include <netdb.h>
 #include <errno.h>
 #include <pwd.h>
+#include <limits.h>
 
 #include "acl.h"
 #include "mboxlist.h"
@@ -96,7 +97,13 @@ static void send_reply(struct sockaddr *
 
 static int soc = 0; /* inetd (master) has handed us the port as stdin */
 
+#ifndef MAXLOGNAME
+#  ifdef LOGIN_NAME_MAX
+#define MAXLOGNAME (LOGIN_NAME_MAX - 1)
+#  else
 #define MAXLOGNAME 16           /* should find out for real */
+#  endif
+#endif
 #define MAXDOMNAME 20           /* should find out for real */
 
 static int begin_handling(void)
