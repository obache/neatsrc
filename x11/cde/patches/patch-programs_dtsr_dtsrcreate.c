$NetBSD$

* <stdlib.h> for atoi(3)

--- programs/dtsr/dtsrcreate.c.orig	2019-10-12 21:43:45.000000000 +0000
+++ programs/dtsr/dtsrcreate.c
@@ -87,11 +87,13 @@
  * Initial revision
  */
 #include "SearchP.h"
+#include "SearchE.h"
 #include <limits.h>
 #include <errno.h>
 #include <ctype.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <stdlib.h>
 #include <locale.h>
 #include "vista.h"
 
