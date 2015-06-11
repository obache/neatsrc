$NetBSD$

* fix condition of netinet/in.h
  https://github.com/groonga/groonga/issues/348

--- src/groonga_benchmark.c.orig	2015-05-25 01:18:03.000000000 +0000
+++ src/groonga_benchmark.c
@@ -33,9 +33,9 @@
 #ifdef HAVE_SYS_SOCKET_H
 #include <sys/socket.h>
 #endif /* HAVE_SYS_SOCKET_H */
-#ifdef HAVE_NETINET_IN_H
+#ifndef WIN32
 #include <netinet/in.h>
-#endif /* HAVE_NETINET_IN_H */
+#endif /* WIN32 */
 
 #include <grn_str.h>
 #include <grn_com.h>
