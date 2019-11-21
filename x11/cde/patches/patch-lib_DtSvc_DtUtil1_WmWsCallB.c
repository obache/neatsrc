$NetBSD$

--- lib/DtSvc/DtUtil1/WmWsCallB.c.orig	2019-11-16 02:06:11.000000000 +0000
+++ lib/DtSvc/DtUtil1/WmWsCallB.c
@@ -38,6 +38,7 @@
  **
  ****************************************************************************
  ************************************<+>*************************************/
+#include <stdlib.h>
 #include <Tt/tttk.h>
 #include <Dt/Service.h>
 #include <Dt/Wsm.h> 
