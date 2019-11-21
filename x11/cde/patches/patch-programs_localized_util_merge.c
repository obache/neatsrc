$NetBSD$

* <unistd.h> for unlink(2)

--- programs/localized/util/merge.c.orig	2019-10-12 21:43:45.000000000 +0000
+++ programs/localized/util/merge.c
@@ -96,6 +96,7 @@
 #include <string.h>
 #include <locale.h>
 #include <nl_types.h>
+#include <unistd.h>
 
 nl_catd catfile[2] = {NULL, NULL};	/* [0] for primary, [1] for default */
 char *big_buff;
