$NetBSD$

* no need to be defined twice

--- libmate-desktop/mate-aboutdialog.c.orig	2015-04-05 17:22:23.000000000 +0000
+++ libmate-desktop/mate-aboutdialog.c
@@ -67,7 +67,6 @@
 static GdkColor default_link_color = { 0, 0, 0, 0xeeee };
 static GdkColor default_visited_link_color = { 0, 0x5555, 0x1a1a, 0x8b8b };
 
-typedef struct _MateAboutDialogPrivate MateAboutDialogPrivate;
 struct _MateAboutDialogPrivate
 {
   gchar *name;
