$NetBSD$

* kill linux-izm

--- util.c.orig	2006-08-01 22:48:00.000000000 +0000
+++ util.c
@@ -3,7 +3,12 @@
 #include <stdarg.h>
 #include <syslog.h>
 #include <arpa/inet.h>
+#ifdef __linux__
 #include <linux/sockios.h>
+#else
+#include <sys/sockio.h>
+#include <sys/socket.h>
+#endif
 #include <net/if.h>
 #include <netinet/in.h>
 #include <sys/ioctl.h>
