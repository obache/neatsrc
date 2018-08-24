$NetBSD$

* include <stdio.h> for snprintf(3)

--- programs/dtsr/dtsrclean.c.orig	2018-07-06 18:05:20.000000000 +0000
+++ programs/dtsr/dtsrclean.c
@@ -96,6 +96,7 @@
  * size from maxdba, not reccount.
  */
 #include "SearchP.h"
+#include <stdio.h>
 #include <stdlib.h>
 #include <ctype.h>
 #include <string.h>
