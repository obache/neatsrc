$NetBSD$

* Add gtk3+ support

--- src/scim_anthy_color_button.cpp.orig	2008-04-24 03:49:53.000000000 +0000
+++ src/scim_anthy_color_button.cpp
@@ -58,9 +58,14 @@ typedef enum
 static void     scim_anthy_color_button_class_init     (ScimAnthyColorButtonClass *klass);
 static void     scim_anthy_color_button_init           (ScimAnthyColorButton      *object);
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+static void     scim_anthy_color_button_destroy (GtkWidget *object);
+static gboolean scim_anthy_color_button_draw (GtkWidget *widget, cairo_t *cr);
+#else
 static void     scim_anthy_color_button_destroy        (GtkObject      *object);
 static gboolean scim_anthy_color_button_expose         (GtkWidget      *widget,
 							GdkEventExpose *eevent);
+#endif
 static gboolean scim_anthy_color_button_button_press   (GtkWidget      *widget,
 							GdkEventButton *bevent);
 static gboolean scim_anthy_color_button_button_release (GtkWidget      *widget,
@@ -100,7 +105,6 @@ scim_anthy_color_button_get_type (void)
 static void
 scim_anthy_color_button_class_init (ScimAnthyColorButtonClass *klass)
 {
-    GtkObjectClass *gtk_object_class = GTK_OBJECT_CLASS (klass);
     GtkWidgetClass *widget_class     = GTK_WIDGET_CLASS (klass);
   
     parent_class = (GtkDrawingAreaClass *) g_type_class_peek_parent (klass);
@@ -114,9 +118,15 @@ scim_anthy_color_button_class_init (Scim
   		  g_cclosure_marshal_VOID__VOID,
   		  G_TYPE_NONE, 0);
   
+#if GTK_CHECK_VERSION(3, 0, 0)
+    widget_class->destroy = scim_anthy_color_button_destroy;
+    widget_class->draw = scim_anthy_color_button_draw;
+#else
+    GtkObjectClass *gtk_object_class = GTK_OBJECT_CLASS (klass);
     gtk_object_class->destroy          = scim_anthy_color_button_destroy;
-  
     widget_class->expose_event         = scim_anthy_color_button_expose;
+#endif
+  
     widget_class->button_press_event   = scim_anthy_color_button_button_press;
     widget_class->button_release_event = scim_anthy_color_button_button_release;
 }
@@ -125,8 +135,13 @@ static void
 scim_anthy_color_button_init (ScimAnthyColorButton *object)
 {
     /*set default color */ 
+#if GTK_CHECK_VERSION(3, 0, 0)
+    gdk_rgba_parse (&object->fg_color, "#000000");
+    gdk_rgba_parse (&object->bg_color, "#ffffff");
+#else
     gdk_color_parse ("#000000", &object->fg_color);
     gdk_color_parse ("#ffffff", &object->bg_color);
+#endif
 
     gtk_widget_add_events (GTK_WIDGET (object),
                     GDK_BUTTON_PRESS_MASK |
@@ -135,7 +150,11 @@ scim_anthy_color_button_init (ScimAnthyC
 
 
 static void
+#if GTK_CHECK_VERSION(3, 0, 0)
+scim_anthy_color_button_destroy (GtkWidget *object)
+#else
 scim_anthy_color_button_destroy (GtkObject *object)
+#endif
 {
     ScimAnthyColorButton *button = SCIM_ANTHY_COLOR_BUTTON (object);
 
@@ -150,19 +169,38 @@ scim_anthy_color_button_destroy (GtkObje
         button->swap_icon = NULL;
     }
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+    GTK_WIDGET_CLASS (parent_class)->destroy (object);
+#else
     GTK_OBJECT_CLASS (parent_class)->destroy (object);
+#endif
 }
 
 static void
 scim_anthy_color_button_draw_rect (ScimAnthyColorButton *button,
+#if GTK_CHECK_VERSION(3, 0, 0)
+                             GdkWindow      *drawable,
+                             cairo_t        *cr,
+#else
                              GdkDrawable    *drawable,
                              GdkGC          *gc,
+#endif
                              gint            x,
                              gint            y,
                              gint            width,
                              gint            height,
-                             GdkColor        *color)
-{
+#if GTK_CHECK_VERSION(3, 0, 0)
+                             GdkRGBA         *color
+#else
+                             GdkColor        *color
+#endif
+                             )
+{
+#if GTK_CHECK_VERSION(3, 0, 0)
+    gdk_cairo_set_source_rgba (cr, color);
+    cairo_rectangle (cr, x, y, width, height);
+    cairo_fill (cr);
+#else
     gint    rowstride;
     guchar  r, g, b;
     gint    xx, yy;
@@ -201,23 +239,38 @@ scim_anthy_color_button_draw_rect (ScimA
                         GDK_RGB_DITHER_MAX,
                         button->render_buf,
                         rowstride);
+#endif
 }
 
 static gboolean
+#if GTK_CHECK_VERSION(3, 0, 0)
+scim_anthy_color_button_draw (GtkWidget      *widget,
+                          cairo_t *cr)
+#else
 scim_anthy_color_button_expose (GtkWidget      *widget,
                           GdkEventExpose *eevent)
+#endif
 {
     ScimAnthyColorButton *button = SCIM_ANTHY_COLOR_BUTTON (widget);
     gint            width, height;
     gint            swap_w = 0, swap_h = 0;
     gint            rect_w, rect_h;
   
+#if GTK_CHECK_VERSION(2, 18, 0)
+      if (!gtk_widget_is_drawable (widget))
+#else
     if (!GTK_WIDGET_DRAWABLE (widget))
+#endif
         return FALSE;
-  
+
+#if GTK_CHECK_VERSION(3, 0, 0)
+    width = gdk_window_get_width(gtk_widget_get_window (widget));
+    height = gdk_window_get_height(gtk_widget_get_window (widget));
+#else
     width  = widget->allocation.width;
     height = widget->allocation.height;
-  
+#endif
+
     /*  draw the swap colors pixbuf  */
     if (!button->swap_icon) {
         button->swap_icon
@@ -231,9 +284,14 @@ scim_anthy_color_button_expose (GtkWidge
     }  
 
     if (swap_w < width / 2 && swap_h < height / 2) {
+#if GTK_CHECK_VERSION(3, 0, 0)
+        gdk_cairo_set_source_pixbuf (cr, button->swap_icon, width - swap_w, 0);
+        cairo_paint (cr);
+#else
         gdk_draw_pixbuf (widget->window, NULL, button->swap_icon,
                          0, 0, width - swap_w, 0, swap_w, swap_h,
                          GDK_RGB_DITHER_NORMAL, 0, 0);
+#endif
     } else {
         swap_w = swap_h = 0;
     }
@@ -249,37 +307,78 @@ scim_anthy_color_button_expose (GtkWidge
     button->rect_width  = rect_w;
     button->rect_height = rect_h;
   
-  
     /*  draw the background area  */
     scim_anthy_color_button_draw_rect (button,
+#if GTK_CHECK_VERSION(2, 14, 0)
+                                 gtk_widget_get_window (widget),
+#else
                                  widget->window,
+#endif
+#if GTK_CHECK_VERSION(3, 0, 0)
+                                 cr,
+#else
                                  widget->style->fg_gc[0],
+#endif
                                  (width - rect_w),
                                  (height - rect_h),
                                  rect_w, rect_h,
                                  &button->bg_color);
   
-    gtk_paint_shadow (widget->style, widget->window, GTK_STATE_NORMAL,
+#if GTK_CHECK_VERSION(3, 0, 0)
+    GtkStyleContext *style = gtk_widget_get_style_context(widget);
+    gtk_style_context_save (style);
+    gtk_style_context_set_state (style, GTK_STATE_FLAG_NORMAL);
+    gtk_render_frame (style, cr, width - rect_w, height - rect_h, rect_w, rect_h);
+#else
+    gtk_paint_shadow (widget->style,
+#if GTK_CHECK_VERSION(2, 14, 0)
+                      gtk_widget_get_window (widget),
+#else
+                      widget->window,
+#endif
+                      GTK_STATE_NORMAL,
                       GTK_SHADOW_IN,
                       NULL, widget, NULL,
                       (width - rect_w),
                       (height - rect_h),
                       rect_w, rect_h);
-  
+#endif 
   
     /*  draw the foreground area  */
     scim_anthy_color_button_draw_rect (button,
+#if GTK_CHECK_VERSION(2, 14, 0)
+                                 gtk_widget_get_window (widget),
+#else
                                  widget->window,
+#endif
+#if GTK_CHECK_VERSION(3, 0, 0)
+                                 cr,
+#else
                                  widget->style->fg_gc[0],
+#endif
                                  0, 0,
                                  rect_w, rect_h,
                                  &button->fg_color);
     
-    gtk_paint_shadow (widget->style, widget->window, GTK_STATE_NORMAL,
-                      GTK_SHADOW_IN,
-                      NULL, widget, NULL,
-                      0, 0,
-                      rect_w, rect_h);
+#if GTK_CHECK_VERSION(3, 0, 0)
+    style = gtk_widget_get_style_context(widget);
+    gtk_style_context_save (style);
+    gtk_style_context_set_state (style, GTK_STATE_FLAG_NORMAL);
+    gtk_render_frame (style, cr, 0, 0, rect_w, rect_h);
+#else
+    gtk_paint_shadow (
+        widget->style, 
+#if GTK_CHECK_VERSION(2, 14, 0)
+        gtk_widget_get_window (widget),
+#else
+        widget->window,
+#endif
+        GTK_STATE_NORMAL,
+        GTK_SHADOW_IN,
+        NULL, widget, NULL,
+        0, 0,
+        rect_w, rect_h);
+#endif
   
     return TRUE;
 }
@@ -289,11 +388,16 @@ scim_anthy_color_button_target (ScimAnth
                           gint            x,
                           gint            y)
 {
+#if GTK_CHECK_VERSION(3, 0, 0)
+    gint width = gdk_window_get_width(gtk_widget_get_window (GTK_WIDGET(button)));
+    gint height = gdk_window_get_height(gtk_widget_get_window (GTK_WIDGET(button)));
+#else
     gint width  = GTK_WIDGET (button)->allocation.width;
     gint height = GTK_WIDGET (button)->allocation.height;
+#endif
     gint rect_w = button->rect_width;
     gint rect_h = button->rect_height;
-  
+
     if (x > 0 && x < rect_w && y > 0 && y < rect_h)
         return FOREGROUND_AREA;
     else if (x > (width - rect_w)  && x < width  &&
@@ -314,7 +418,11 @@ scim_anthy_color_button_open_color_dialo
 {
     GtkWidget *dialog;
     const gchar *title;
+#if GTK_CHECK_VERSION(3, 0, 0)
+    GdkRGBA *color;
+#else
     GdkColor *color;
+#endif
     gint result;
   
     title = fg ? _("Foreground color") : _("Background color");
@@ -322,16 +430,38 @@ scim_anthy_color_button_open_color_dialo
     
     dialog = gtk_color_selection_dialog_new (title);
 
-    gtk_color_selection_set_current_color (GTK_COLOR_SELECTION (GTK_COLOR_SELECTION_DIALOG (dialog)->colorsel),
-                                           color);
+#if GTK_CHECK_VERSION(3, 0, 0)
+    gtk_color_selection_set_current_rgba (
+        GTK_COLOR_SELECTION (gtk_color_selection_dialog_get_color_selection (GTK_COLOR_SELECTION_DIALOG (dialog))),
+        color);
+#else
+    gtk_color_selection_set_current_color (
+#if GTK_CHECK_VERSION(2, 14, 0)
+        GTK_COLOR_SELECTION (gtk_color_selection_dialog_get_color_selection (GTK_COLOR_SELECTION_DIALOG (dialog))),
+#else
+        GTK_COLOR_SELECTION (GTK_COLOR_SELECTION_DIALOG (dialog)->colorsel),
+#endif
+        color);
+#endif
     gtk_widget_show (dialog);
 
     result = gtk_dialog_run (GTK_DIALOG (dialog));
 
     switch (result) {
         case GTK_RESPONSE_OK:
-            gtk_color_selection_get_current_color (GTK_COLOR_SELECTION (GTK_COLOR_SELECTION_DIALOG (dialog)->colorsel),
-                                                   color);
+#if GTK_CHECK_VERSION(3, 0, 0)
+            gtk_color_selection_get_current_rgba (
+                GTK_COLOR_SELECTION (gtk_color_selection_dialog_get_color_selection (GTK_COLOR_SELECTION_DIALOG (dialog))),
+                color);
+#else
+            gtk_color_selection_get_current_color (
+#if GTK_CHECK_VERSION(2, 14, 0)
+                GTK_COLOR_SELECTION (gtk_color_selection_dialog_get_color_selection (GTK_COLOR_SELECTION_DIALOG (dialog))),
+#else
+                GTK_COLOR_SELECTION (GTK_COLOR_SELECTION_DIALOG (dialog)->colorsel),
+#endif
+                color);
+#endif
             g_signal_emit (button, button_signals[COLOR_CHANGED], 0);
             break;
         default:
@@ -345,6 +475,11 @@ scim_anthy_color_button_open_color_dialo
 static void
 scim_anthy_color_button_swap_color (ScimAnthyColorButton *button)
 {
+#if GTK_CHECK_VERSION(3, 0, 0)
+    GdkRGBA tmp = button->fg_color;
+    button->fg_color = button->bg_color;
+    button->bg_color = tmp;
+#else
     GdkColor tmp;
     tmp.red   = button->fg_color.red;
     tmp.green = button->fg_color.green;
@@ -357,6 +492,7 @@ scim_anthy_color_button_swap_color (Scim
     button->bg_color.red   = tmp.red;
     button->bg_color.green = tmp.green;
     button->bg_color.blue  = tmp.blue;
+#endif
     g_signal_emit (button, button_signals[COLOR_CHANGED], 0);
 }
 
@@ -447,14 +583,29 @@ scim_anthy_color_button_get_colors (Scim
 
     g_snprintf (fg_color_str, G_N_ELEMENTS (fg_color_str),
                 "#%02X%02X%02X", 
+#if GTK_CHECK_VERSION(3, 0, 0)
+                static_cast<unsigned int>(255*button->fg_color.red),
+                static_cast<unsigned int>(255*button->fg_color.green),
+                static_cast<unsigned int>(255*button->fg_color.blue)
+#else
                 ((button->fg_color.red)>>8),
                 ((button->fg_color.green)>>8),
-                ((button->fg_color.blue)>>8));
+                ((button->fg_color.blue)>>8)
+#endif
+                );
     g_snprintf (bg_color_str, G_N_ELEMENTS (bg_color_str),
                 "#%02X%02X%02X", 
+#if GTK_CHECK_VERSION(3, 0, 0)
+                static_cast<unsigned int>(255*button->bg_color.red),
+                static_cast<unsigned int>(255*button->bg_color.green),
+                static_cast<unsigned int>(255*button->bg_color.blue)
+#else
                 ((button->bg_color.red)>>8),
                 ((button->bg_color.green)>>8),
-                ((button->bg_color.blue)>>8));
+                ((button->bg_color.blue)>>8)
+#endif
+                );
+
     *fg_value = String (fg_color_str); 
     *bg_value = String (bg_color_str); 
 
@@ -466,6 +617,10 @@ scim_anthy_color_button_set_colors (Scim
 				    const String &fg_value,
 				    const String &bg_value)
 {
+#if GTK_CHECK_VERSION(3, 0, 0)
+    gdk_rgba_parse (&button->fg_color, fg_value.c_str()); 
+    gdk_rgba_parse (&button->bg_color, bg_value.c_str()); 
+#else
     GdkColor fg_color, bg_color;
     gdk_color_parse (fg_value.c_str (), &fg_color);
     gdk_color_parse (bg_value.c_str (), &bg_color);
@@ -476,6 +631,7 @@ scim_anthy_color_button_set_colors (Scim
     button->bg_color.red   = bg_color.red;
     button->bg_color.green = bg_color.green;
     button->bg_color.blue  = bg_color.blue;
+#endif
 
     return TRUE;
 }
