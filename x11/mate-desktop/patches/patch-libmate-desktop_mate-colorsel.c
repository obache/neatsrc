$NetBSD$

* no need to be defined twice

--- libmate-desktop/mate-colorsel.c.orig	2015-04-05 17:22:23.000000000 +0000
+++ libmate-desktop/mate-colorsel.c
@@ -88,8 +88,6 @@ enum {
   COLORSEL_NUM_CHANNELS
 };
 
-typedef struct _ColorSelectionPrivate ColorSelectionPrivate;
-
 struct _ColorSelectionPrivate
 {
   guint has_opacity : 1;
