$NetBSD$

* for malloc

--- mana/tools.c.orig	2005-08-07 18:05:59.000000000 +0000
+++ mana/tools.c
@@ -17,6 +17,7 @@
 
 #include <string.h>
 #include <stdio.h>
+#include <stdlib.h>
 
 char *null_string(void){
   char *s;
