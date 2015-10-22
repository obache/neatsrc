$NetBSD$

* ghostscript-9.18 "Consolidate almost all error codes" change

--- libspectre/spectre-gs.c.orig	2015-10-22 06:01:02.000000000 +0000
+++ libspectre/spectre-gs.c
@@ -29,6 +29,16 @@
 #include <ghostscript/iapi.h>
 #include <ghostscript/ierrors.h>
 
+#ifndef e_Fatal
+#define e_Fatal gs_error_Fatal
+#endif
+#ifndef e_ExecStackUnderflow
+#define e_ExecStackUnderflow gs_error_ExecStackUnderflow
+#endif
+#ifndef e_NeedInput
+#define e_NeedInput gs_error_NeedInput
+#endif
+
 #define BUFFER_SIZE 32768
 
 struct SpectreGS {
