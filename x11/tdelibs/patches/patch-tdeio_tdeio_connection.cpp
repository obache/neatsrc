$NetBSD$

--- tdeio/tdeio/connection.cpp.orig	2020-04-10 23:08:30.000000000 +0000
+++ tdeio/tdeio/connection.cpp
@@ -42,8 +42,10 @@
 #include <kdebug.h>
 #include <tqsocketnotifier.h>
 
-#if defined(__OpenBSD__) || defined(__FreeBSD__)
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #define __progname getprogname()
+#elif defined(_GNU_SOURCE) && defined(__GLIBC__)
+#define __progname program_invocation_short_name
 #else
 extern char *__progname;
 #endif
