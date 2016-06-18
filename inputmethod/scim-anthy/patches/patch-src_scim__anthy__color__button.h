$NetBSD$

* Add gtk3+ support

--- src/scim_anthy_color_button.h.orig	2008-04-24 03:49:53.000000000 +0000
+++ src/scim_anthy_color_button.h
@@ -53,8 +53,13 @@ struct _ScimAnthyColorButton
   gint             rect_height;
   gint             click_target;
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+  GdkRGBA          fg_color;
+  GdkRGBA          bg_color;
+#else
   GdkColor         fg_color;
-  GdkColor	   bg_color;
+  GdkColor	       bg_color;
+#endif
 };
 
 struct _ScimAnthyColorButtonClass
