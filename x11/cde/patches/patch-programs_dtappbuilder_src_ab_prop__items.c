$NetBSD$

* disable to force old standard, or new features (ex. snprintf(3) will be hidden

--- programs/dtappbuilder/src/ab/prop_items.c.orig	2018-07-06 18:05:20.000000000 +0000
+++ programs/dtappbuilder/src/ab/prop_items.c
@@ -47,10 +47,6 @@
  *
  *****************************************************************
  */
-#ifndef _POSIX_SOURCE
-#define _POSIX_SOURCE 1
-#endif
-
 #include <stdio.h>
 #include <stdlib.h>
 #include <ctype.h>
