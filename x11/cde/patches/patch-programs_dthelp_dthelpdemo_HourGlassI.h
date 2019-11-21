$NetBSD$

* fix function name implemented in HourGlass.c

--- programs/dthelp/dthelpdemo/HourGlassI.h.orig	2019-10-12 21:43:45.000000000 +0000
+++ programs/dthelp/dthelpdemo/HourGlassI.h
@@ -52,7 +52,7 @@
  *   which is passed in to the funciton.
  */
 
-extern void _DtHelpTurnOnHourGlass(
+extern void TurnOnHourGlass(
     Widget widget);
 
  /*
@@ -67,7 +67,7 @@ extern void _DtHelpTurnOnHourGlass(
  *   which is passed in to the funciton.
  */
 
-extern void _DtHelpTurnOffHourGlass(
+extern void TurnOffHourGlass(
     Widget widget);
 
  /*
