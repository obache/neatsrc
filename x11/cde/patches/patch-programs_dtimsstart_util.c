$NetBSD$

* <ctype.h> for isdigit(3)

--- programs/dtimsstart/util.c.orig	2019-10-12 21:43:45.000000000 +0000
+++ programs/dtimsstart/util.c
@@ -23,6 +23,7 @@
 /* @(#)$XConsortium: util.c /main/6 1996/07/12 15:44:21 pascale $ */
 
 #include <time.h>
+#include <ctype.h>
 #include <DtHelp/LocaleXlate.h>  /* for locale equivalence between platforms */
 #include "xims.h"
 #include <sys/stat.h>
@@ -262,14 +263,14 @@ bool	parse_dpy_str(char *display_str, ch
     if (p = strchr(hp, '.'))	*p = 0;
 
 	/* extract display number */
-    for (p = pdnum; *p && isdigit(*p); p++) ;
+    for (p = pdnum; *p && isdigit((unsigned char)*p); p++) ;
     if (p == pdnum || (*p && *p != '.'))
 	return False;
 
     psnum = NULL;
     if (*p) {	/* extract screen number */
 	*p++ = 0;	/* must be '.' */
-	for (psnum = p; *p && isdigit(*p); p++) ;
+	for (psnum = p; *p && isdigit((unsigned char)*p); p++) ;
 	if (p == psnum || *p)	psnum = NULL;
 	*p++ = 0;
     }
