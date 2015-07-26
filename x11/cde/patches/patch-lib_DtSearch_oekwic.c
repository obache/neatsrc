$NetBSD$

--- lib/DtSearch/oekwic.c.orig	2015-05-09 23:09:11.000000000 +0000
+++ lib/DtSearch/oekwic.c
@@ -59,6 +59,7 @@
  */
 #include "SearchE.h"
 #include <ctype.h>
+#include <time.h>
 
 /******#define DEBUG_KWIC*********/
 /********#define DEBUG_FINDSTR_ITER***********/
