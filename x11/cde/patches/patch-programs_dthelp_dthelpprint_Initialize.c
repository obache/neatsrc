$NetBSD$

* "StringFuncsI.h for _DtHelpCeStrrchr()
* use strcasecmp unconcitionnally

--- programs/dthelp/dthelpprint/Initialize.c.orig	2019-11-16 02:06:11.000000000 +0000
+++ programs/dthelp/dthelpprint/Initialize.c
@@ -53,6 +53,7 @@ $COPYRIGHT$:
 /* don't use X11/StringDefs.h because it brings in the _XtStrings global */
 
 #include "HelpPrintI.h"
+#include "StringFuncsI.h"
 
 /*#define DEBUG	*/
 
@@ -793,7 +794,6 @@ void CalculatePageSize(
 static float dphm = 300.*2540.;
 #endif
 
-   int  (*stricmp)(const char *,const char *);
    char *name;
    char name_prefix[RSRCSPECLEN];
    char name_prefix_temp[sizeof(name_prefix)];
@@ -879,19 +879,14 @@ static float dphm = 300.*2540.;
    strcat(resource_class, RC_paperSize); 
                          /* e.g. Dthelpprint.Printer{.<name>}.PaperSize */
    
-#if defined(_AIX)
-   stricmp = strcmp;	/* AIX and USL don't have strcasecmp */
-#else
-   stricmp = strcasecmp;
-#endif
    if (XrmGetResource(appDB, resource_name, resource_class, 
                       str_type, &value) == True)
    {
-      if ((*stricmp)(value.addr, RV_letter) == 0) papersize = LETTER;
-      else if ((*stricmp)(value.addr, RV_b5) == 0) papersize = B5;
-      else if ((*stricmp)(value.addr, RV_a4) == 0) papersize = A4;
-      else if ((*stricmp)(value.addr, RV_legal) == 0) papersize = LEGAL;
-      else if ((*stricmp)(value.addr, RV_executive) == 0) papersize = EXECUTIVE;
+      if (strcasecmp(value.addr, RV_letter) == 0) papersize = LETTER;
+      else if (strcasecmp(value.addr, RV_b5) == 0) papersize = B5;
+      else if (strcasecmp(value.addr, RV_a4) == 0) papersize = A4;
+      else if (strcasecmp(value.addr, RV_legal) == 0) papersize = LEGAL;
+      else if (strcasecmp(value.addr, RV_executive) == 0) papersize = EXECUTIVE;
       else 
       {
 	 fprintf(stderr, _DTGETMESSAGE(INSET,40,
