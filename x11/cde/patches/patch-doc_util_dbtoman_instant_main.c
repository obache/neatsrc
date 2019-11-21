$NetBSD$

* <unistd.h> for getopt(3)

--- doc/util/dbtoman/instant/main.c.orig	2019-10-12 21:43:45.000000000 +0000
+++ doc/util/dbtoman/instant/main.c
@@ -97,6 +97,7 @@
 #include <sys/stat.h>
 #include <sys/file.h>
 #include <time.h>
+#include <unistd.h>
 
 #define STORAGE
 #include "general.h"
