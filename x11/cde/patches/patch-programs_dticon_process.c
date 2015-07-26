$NetBSD$

--- programs/dticon/process.c.orig	2015-05-09 23:09:11.000000000 +0000
+++ programs/dticon/process.c
@@ -84,6 +84,7 @@
 #include <Xm/TextF.h>
 #include "externals.h"
 #include <string.h>
+#include <stdlib.h>
 
 #include <Xm/DragC.h>
 #include <Dt/Dnd.h>
