$NetBSD$

* declare used function

--- programs/dtsr/dtsrhan.c.orig	2019-10-12 21:43:45.000000000 +0000
+++ programs/dtsr/dtsrhan.c
@@ -109,6 +109,8 @@
 #include <time.h>
 #include <locale.h>
 
+extern char	*strupr (char*);
+
 #define PROGNAME	"DTSRHAN"
 #define	MS_chandel	5
 #define RECS_PER_DOT	10L
