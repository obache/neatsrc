$NetBSD$

* Fix for 64bit time_t on 32bit arch

--- plugins/cram.c.orig	2012-01-27 23:31:36.000000000 +0000
+++ plugins/cram.c
@@ -137,7 +137,7 @@ static char *gettime(sasl_server_params_
     
     /* the bottom bits are really the only random ones so if
        we overflow we don't want to loose them */
-    snprintf(ret,15,"%lu",t%(0xFFFFFF));
+    snprintf(ret,15,"%lu",(unsigned long)t%(0xFFFFFF));
     
     return ret;
 }
