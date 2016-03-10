$NetBSD$

* Fix for missing O_CLOEXEC

--- if.h.orig	2016-01-20 19:08:12.000000000 +0000
+++ if.h
@@ -161,3 +161,15 @@ int if_initrt6(struct interface *);
 int if_machinearch(char *, size_t);
 int xsocket(int, int, int, int);
 #endif
+
+#ifdef SOCK_CLOEXEC
+# define HAVE_SOCK_CLOEXEC
+#else
+# define SOCK_CLOEXEC 0x10000000
+#endif
+
+#ifdef SOCK_NONBLOCK
+# define HAVE_SOCK_NONBLOCK
+#else
+# define SOCK_NONBLOCK 0x20000000
+#endif
