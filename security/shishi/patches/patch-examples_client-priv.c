$NetBSD$

* buildable with updated gnulib

--- examples/client-priv.c.orig	2013-04-02 22:52:55.000000000 +0000
+++ examples/client-priv.c
@@ -21,6 +21,10 @@
  *
  */
 
+#ifdef HAVE_CONFIG_H
+# include <config.h>
+#endif
+
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
