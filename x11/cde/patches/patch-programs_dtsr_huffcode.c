$NetBSD$

* include <stdio.h> for snprintf(3)

--- programs/dtsr/huffcode.c.orig	2018-07-06 18:05:20.000000000 +0000
+++ programs/dtsr/huffcode.c
@@ -144,6 +144,7 @@
 #include <locale.h>
 #include <sys/stat.h>
 #include <stdlib.h>
+#include <stdio.h>
 
 #define MS_huff		30	/* message catalog set number */
 #define DELIMITERS	"\t\n"	/* betw fields in .huf file */
