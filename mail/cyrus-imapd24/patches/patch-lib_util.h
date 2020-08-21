$NetBSD$

* <ctype.h> for `isspace(3)`

--- lib/util.h.orig	2020-08-19 00:54:54.000000000 +0000
+++ lib/util.h
@@ -52,6 +52,7 @@
 #include <sys/types.h>
 #include <limits.h>
 #include <stdarg.h>
+#include <ctype.h>
 
 #define BIT32_MAX 4294967295U
 
