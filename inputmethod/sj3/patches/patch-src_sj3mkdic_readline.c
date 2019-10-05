$NetBSD$

* <stdlib.h> for exit(3).
* fix to be match with prototype

--- src/sj3mkdic/readline.c.orig	2010-02-14 12:20:37.000000000 +0000
+++ src/sj3mkdic/readline.c
@@ -35,6 +35,7 @@
 
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <sys/types.h>
 #include <ctype.h>
 
@@ -277,7 +278,7 @@ readline()
 
 
 void
-setline(int (*func)())
+setline(void (*func)(int *, int *, int, int *))
 {
 	int	i;
 
