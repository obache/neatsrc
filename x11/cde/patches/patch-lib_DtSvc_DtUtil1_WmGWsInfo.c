$NetBSD$

* <stlib.h> for atoi(3) and strtol(3)

--- lib/DtSvc/DtUtil1/WmGWsInfo.c.orig	2019-10-12 21:43:45.000000000 +0000
+++ lib/DtSvc/DtUtil1/WmGWsInfo.c
@@ -43,6 +43,7 @@
  ****************************************************************************
  ************************************<+>*************************************/
 #include <stdio.h>
+#include <stdlib.h>
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
 #include <Dt/Wsm.h> 
