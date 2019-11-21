$NetBSD$

* use strcasecmp unconditionally

--- programs/dthelp/parser/pass1/helptag/special.c.orig	2019-11-16 02:06:11.000000000 +0000
+++ programs/dthelp/parser/pass1/helptag/special.c
@@ -121,6 +121,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 
 typedef wchar_t M_WCHAR;
 
@@ -146,9 +147,9 @@ if (argc < 3)
     { /*  Either one argument or none; not more */
     if (argc == 2)
 	{
-	if (!stricmp(argv[1], "b")) both = TRUE;
-	else if (!stricmp(argv[1], "s")) spec = TRUE;
-	else if (!stricmp(argv[1], "c")) coll = TRUE;
+	if (!strcasecmp(argv[1], "b")) both = TRUE;
+	else if (!strcasecmp(argv[1], "s")) spec = TRUE;
+	else if (!strcasecmp(argv[1], "c")) coll = TRUE;
 	else error = TRUE;
 	}
     else both = TRUE;
