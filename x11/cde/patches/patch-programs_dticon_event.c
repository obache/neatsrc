$NetBSD$

* <stdlib.h> for atoi(3)

--- programs/dticon/event.c.orig	2019-10-12 21:43:45.000000000 +0000
+++ programs/dticon/event.c
@@ -56,6 +56,7 @@
  **
  ******************************************************************************/
 #include <stdio.h>
+#include <stdlib.h>
 
 #include <Xm/Xm.h>
 #include "externals.h"
