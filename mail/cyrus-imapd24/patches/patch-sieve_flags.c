$NetBSD$

* <string.h> for `strcmp(3)`

--- sieve/flags.c.orig	2020-08-19 00:54:54.000000000 +0000
+++ sieve/flags.c
@@ -10,6 +10,7 @@
 #include "strarray.h"
 #include "util.h"
 #include "xmalloc.h"
+#include <string.h>
 
 static int verify_flag(char *f)
 {
