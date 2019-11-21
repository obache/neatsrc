$NetBSD$

* <unistd.h> for unlink(2)

--- programs/localized/util/mkcatdefs.c.orig	2019-10-12 21:43:45.000000000 +0000
+++ programs/localized/util/mkcatdefs.c
@@ -48,6 +48,7 @@
 #include <locale.h>
 #include <ctype.h>
 #include <ctype.h>
+#include <unistd.h>
 
 #ifdef aix
 #include <sys/dir.h>
