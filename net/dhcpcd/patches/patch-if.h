$NetBSD$

* Fix for missing O_CLOEXEC

--- if.h.orig	2016-01-20 19:08:12.000000000 +0000
+++ if.h
@@ -114,6 +114,19 @@ int if_managelink(struct dhcpcd_ctx *);
 #define RTM_GET		0x4	/* Report Metrics */
 #endif
 
+/* Define SOCK_CLOEXEC and SOCK_NONBLOCK for system that lack it.
+ * xsocket() in if.c will map them to fctnl FD_CLOEXEC and O_NONBLOCK. */
+#ifdef SOCK_CLOEXEC
+# define HAVE_SOCK_CLOEXEC
+#else
+# define SOCK_CLOEXEC	0x10000000
+#endif
+#ifdef SOCK_NONBLOCK
+# define HAVE_SOCK_NONBLOCK
+#else
+# define SOCK_NONBLOCK	0x20000000
+#endif
+
 #ifdef INET
 extern const char *if_pfname;
 int if_openrawsocket(struct interface *, uint16_t);
