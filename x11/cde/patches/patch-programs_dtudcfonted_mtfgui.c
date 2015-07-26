$NetBSD$

--- programs/dtudcfonted/mtfgui.c.orig	2015-05-09 23:09:11.000000000 +0000
+++ programs/dtudcfonted/mtfgui.c
@@ -579,7 +579,7 @@ int code;
     char str[8];
 
     if (! code){
-	str[0] = NULL;
+	str[0] = '\0';
     }
     else{
 	sprintf( str, "%4x:", code );
