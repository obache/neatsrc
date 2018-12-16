$NetBSD$

* Make inline to be static inline where relevant (to be compatible with C99)

--- xgnokii/xgnokii.c.orig	2011-12-02 14:53:04.000000000 +0000
+++ xgnokii/xgnokii.c
@@ -798,7 +798,7 @@ inline void GUI_ShowAbout(void)
 }
 
 
-inline void GUI_HideAbout(void)
+static inline void GUI_HideAbout(void)
 {
 	gtk_widget_hide(AboutDialog);
 }
