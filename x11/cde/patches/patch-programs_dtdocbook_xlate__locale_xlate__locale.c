$NetBSD$

* <string.h> for strcmp(3)

--- programs/dtdocbook/xlate_locale/xlate_locale.c.orig	2019-10-12 21:43:45.000000000 +0000
+++ programs/dtdocbook/xlate_locale/xlate_locale.c
@@ -22,6 +22,7 @@
  */
 #include <stdlib.h>
 #include <stdio.h>
+#include <string.h>
 #include "LocaleXlate.h"
 #include "XlationSvc.h"
 
