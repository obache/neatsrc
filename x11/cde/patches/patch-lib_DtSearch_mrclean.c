$NetBSD$

--- lib/DtSearch/mrclean.c.orig	2015-05-09 23:09:11.000000000 +0000
+++ lib/DtSearch/mrclean.c
@@ -91,6 +91,7 @@
 #include <errno.h>
 #include <signal.h>
 #include <sys/stat.h>
+#include <time.h>
 #include "vista.h"
 
 #define XOS_USE_NO_LOCKING
