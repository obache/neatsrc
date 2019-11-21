$NetBSD$

* handled well in AccessI.h
* missing prototypes for private DtHelpTerm

--- programs/dthelp/dthelpprint/PrintTopics.c.orig	2019-11-16 02:06:11.000000000 +0000
+++ programs/dthelp/dthelpprint/PrintTopics.c
@@ -61,6 +61,7 @@ $COPYRIGHT$:
 #include "HelpPrintI.h"  /* helpprint */
 
 #include "HelpTermP.h"	/* from libDtHelp */
+#include "HelpXlate.h" /* from libDtHelp */
 #include "CanvasP.h"	/* from libDtHelp */
 #include "StringFuncsI.h" /* from libDtHelp */
 #include "LocaleXlate.h" /* from libDtHelp */
@@ -68,12 +69,17 @@ $COPYRIGHT$:
 #include "FileUtilsI.h" /* from libDtHelp */
 #include "GenUtilsP.h" /* from libDtHelp */
 
-/*#include "AccessI.h" ** from libDtHelp */
-/* I can't include AccessI.h because it redefines the Boolean type,
-which is also defined in Xt/Intrisincs.h.  I'm just including the
-prototypes from AccessI.h here. */
-extern char * _DtHelpCeGetVolumeLocale(VolumeHandle helpVolumeHandle);
-extern const char * _DtHelpCeGetVolumeCharSet(VolumeHandle helpVolumeHandle);
+#include "Access.h"  /* from libDtHelp; required for AccessI.h */
+#include "AccessI.h" /* from libDtHelp */
+#include "ObsoleteP.h"
+extern int _DtHelpTermCreateCanvas (int maxColumns,_DtCvHandle * ret_canvas);
+extern int
+_DtHelpTermGetTopicData(
+    _DtCvHandle      canvasHandle,
+    _DtHelpVolumeHdl      volHandle,
+    char *            locationId,
+    char * * *	      helpList,
+    DtHelpHyperLines ** hyperList);
 
 /*======== platform adjustments ==============*/
 #ifdef sun
