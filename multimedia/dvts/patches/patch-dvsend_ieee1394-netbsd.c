$NetBSD$

* for mem*
* NULL is not 0

--- dvsend/ieee1394-netbsd.c.orig	2008-03-12 10:28:07.000000000 +0000
+++ dvsend/ieee1394-netbsd.c
@@ -43,6 +43,8 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 
+#include <string.h>
+
 #include <dvts.h>
 
 #include "param.h"
@@ -99,7 +101,7 @@ main_loop (struct dvsend_param *dvsend_p
 
     /* just do RTCP process sometimes */
     if ((dvsend_param->flags & USE_RTCP) && readcount % 1000) {
-      if (gettimeofday(&tv, NULL) < NULL) {
+      if (gettimeofday(&tv, NULL) < 0) {
         printf("gettimeofday failed\n");
         break;
       }
