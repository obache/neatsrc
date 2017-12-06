$NetBSD$

* buildable with updated gnulib

--- examples/server.c.orig	2013-04-02 22:52:55.000000000 +0000
+++ examples/server.c
@@ -20,6 +20,10 @@
  *
  */
 
+#ifdef HAVE_CONFIG_H
+# include <config.h>
+#endif
+
 #include <stdio.h>
 #include <stdlib.h>
 
