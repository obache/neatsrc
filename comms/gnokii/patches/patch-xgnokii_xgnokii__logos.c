$NetBSD$

* Make inline to be static inline where relevant (to be compatible with C99)

--- xgnokii/xgnokii_logos.c.orig	2011-12-02 14:53:04.000000000 +0000
+++ xgnokii/xgnokii_logos.c
@@ -1304,7 +1304,7 @@ gint LogoTypeEvent(GtkWidget * widget)
 	return 0;
 }
 
-inline void CloseLogosWindow(void)
+static inline void CloseLogosWindow(void)
 {
 	gtk_widget_hide(GUI_LogosWindow);
 }
