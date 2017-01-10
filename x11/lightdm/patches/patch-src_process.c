$NetBSD$

* for missing cleanenv(3) but "environ" is not declared

--- src/process.c.orig	2015-10-22 03:01:59.000000000 +0000
+++ src/process.c
@@ -19,6 +19,10 @@
 #include <grp.h>
 #include <config.h>
 
+#ifndef HAVE_CLEARENV
+extern char **environ;
+#endif
+
 #include "log-file.h"
 #include "process.h"
 
