$NetBSD$

* stdlib.h is required for malloc(3)

--- libcaja-private/caja-undostack-manager.c.orig	2015-06-11 20:59:47.000000000 +0000
+++ libcaja-private/caja-undostack-manager.c
@@ -33,6 +33,7 @@
 #include <glib/gi18n.h>
 #include <locale.h>
 #include <gdk/gdk.h>
+#include <stdlib.h>
 
 /* *****************************************************************
  Private fields
