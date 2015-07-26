$NetBSD$

--- programs/dtwm/WmOL.c.orig	2015-05-09 23:09:11.000000000 +0000
+++ programs/dtwm/WmOL.c
@@ -39,6 +39,7 @@ static char rcsid[] = "$XConsortium: WmO
 #include "WmOL.h"
 #include "WmProperty.h"
 #include <Xm/AtomMgr.h>
+#include <stdlib.h>
 
 #define ValidPropertyList(pcd) ((pcd)->paInitialProperties != NULL)
 
