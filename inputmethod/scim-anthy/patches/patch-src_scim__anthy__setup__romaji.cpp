$NetBSD$

* add gtk3+ support

--- src/scim_anthy_setup_romaji.cpp.orig	2008-04-24 03:49:53.000000000 +0000
+++ src/scim_anthy_setup_romaji.cpp
@@ -55,14 +55,14 @@ static String __config_romaji_theme_file
 static GtkWidget *create_romaji_window            (GtkWindow            *parent);
 
 static void     setup_romaji_page                 (void);
-static void     setup_romaji_theme_menu           (GtkOptionMenu        *omenu);
+static void     setup_romaji_theme_menu           (GtkWidget *omenu);
 static void     setup_romaji_window_value         (ScimAnthyTableEditor *editor);
 
 static bool     load_romaji_theme                 (void);
 
 static void     on_romaji_pseudo_ascii_mode_toggled(GtkToggleButton *togglebutton,
                                                     gpointer         user_data);
-static void     on_romaji_theme_menu_changed       (GtkOptionMenu        *omenu,
+static void     on_romaji_theme_menu_changed       (GtkWidget *omenu,
                                                     gpointer              user_data);
 static void     on_romaji_customize_button_clicked (GtkWidget            *button,
                                                     gpointer              data);
@@ -80,7 +80,11 @@ romaji_page_create_ui (void)
 {
     GtkWidget *vbox, *widget, *hbox, *label;
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+    vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
+#else
     vbox = gtk_vbox_new (FALSE, 0);
+#endif
     gtk_widget_show (vbox);
 
     /* romaji splitting */
@@ -103,7 +107,11 @@ romaji_page_create_ui (void)
     gtk_box_pack_start (GTK_BOX (vbox), widget, FALSE, FALSE, 4);
 
     /* pseudo ascii: blank behavior */
+#if GTK_CHECK_VERSION(3, 0, 0)
+    hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
+#else
     hbox = gtk_hbox_new (FALSE, 0);
+#endif
     gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 4);
     gtk_widget_show (hbox);
     label = gtk_label_new ("    ");
@@ -116,7 +124,11 @@ romaji_page_create_ui (void)
     on_romaji_pseudo_ascii_mode_toggled (GTK_TOGGLE_BUTTON (widget), NULL);
 
     /* romaji table */
+#if GTK_CHECK_VERSION(3, 0, 0)
+    hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
+#else
     hbox = gtk_hbox_new (FALSE, 0);
+#endif
     gtk_container_set_border_width (GTK_CONTAINER (hbox), 4);
     gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);
     gtk_widget_show(hbox);
@@ -125,7 +137,11 @@ romaji_page_create_ui (void)
     gtk_box_pack_start (GTK_BOX (hbox), label, FALSE, FALSE, 2);
     gtk_widget_show (label);
 
+#if GTK_CHECK_VERSION(2, 24, 0)
+    GtkWidget *omenu = gtk_combo_box_text_new ();
+#else
     GtkWidget *omenu = gtk_option_menu_new ();
+#endif
     __widget_romaji_theme_menu = omenu;
     g_signal_connect (G_OBJECT (omenu), "changed",
                       G_CALLBACK (on_romaji_theme_menu_changed), NULL);
@@ -185,27 +201,52 @@ create_romaji_window (GtkWindow *parent)
                           _("Customize romaji table"));
 
     // option menu area
+#if GTK_CHECK_VERSION(3, 0, 0)
+    GtkWidget *hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
+#else
     GtkWidget *hbox = gtk_hbox_new (FALSE, 0);
+#endif
+
     gtk_container_set_border_width (GTK_CONTAINER (hbox), 4);
+
+#if GTK_CHECK_VERSION(3, 0, 0)
+    gtk_box_pack_start
+		(GTK_BOX (gtk_dialog_get_content_area (GTK_DIALOG (dialog))),
+		 hbox, FALSE, FALSE, 0);
+    gtk_box_reorder_child 
+		(GTK_BOX (gtk_dialog_get_content_area (GTK_DIALOG (dialog))),
+		 hbox, 0);
+#else
     gtk_box_pack_start (GTK_BOX (GTK_DIALOG (dialog)->vbox), hbox,
                         FALSE, FALSE, 0);
     gtk_box_reorder_child (GTK_BOX (GTK_DIALOG (dialog)->vbox), hbox, 0);
+#endif
+
     gtk_widget_show(hbox);
 
     GtkWidget *label = gtk_label_new_with_mnemonic (_("Romaji _table:"));
     gtk_box_pack_start (GTK_BOX (hbox), label, FALSE, FALSE, 2);
     gtk_widget_show (label);
 
+#if GTK_CHECK_VERSION(2, 24, 0)
+    GtkWidget *omenu = gtk_combo_box_text_new ();
+#else
     GtkWidget *omenu = gtk_option_menu_new ();
+#endif
     __widget_romaji_theme_menu2 = omenu;
     g_object_add_weak_pointer (G_OBJECT (omenu),
                                (gpointer*) &__widget_romaji_theme_menu2);
     gtk_box_pack_start (GTK_BOX (hbox), omenu, FALSE, FALSE, 2);
-    setup_romaji_theme_menu (GTK_OPTION_MENU (omenu));
+    setup_romaji_theme_menu (omenu);
+#if GTK_CHECK_VERSION(2, 24, 0)
+    gtk_combo_box_set_active (GTK_COMBO_BOX (omenu),
+         gtk_combo_box_get_active (GTK_COMBO_BOX (__widget_romaji_theme_menu)));
+#else
     gtk_option_menu_set_history
         (GTK_OPTION_MENU (omenu),
          gtk_option_menu_get_history (
              GTK_OPTION_MENU (__widget_romaji_theme_menu)));
+#endif
     gtk_widget_show (omenu);
 
     gtk_label_set_mnemonic_widget (GTK_LABEL(label), omenu);
@@ -240,12 +281,47 @@ create_romaji_window (GtkWindow *parent)
 static void
 setup_romaji_page (void)
 {
-    setup_romaji_theme_menu (GTK_OPTION_MENU (__widget_romaji_theme_menu));
+    setup_romaji_theme_menu (__widget_romaji_theme_menu);
 }
 
 static void
-setup_romaji_theme_menu (GtkOptionMenu *omenu)
+setup_romaji_theme_menu (GtkWidget *omenu)
 {
+#if GTK_CHECK_VERSION(2, 24, 0)
+	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (omenu), _("User defined"));
+	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (omenu), _("Default"));
+
+	gint active_index = ROMAJI_THEME_INDEX_DEFAULT;
+    bool check_list = false;
+    if (__config_romaji_theme_file == __user_style_file.get_file_name ()) {
+		active_index = ROMAJI_THEME_INDEX_USER_DEFINED;
+	} else {
+        check_list = true;
+	}
+
+    StyleFiles::iterator it;
+    unsigned int i;
+    for (i = 0, it = __style_list.begin ();
+         it != __style_list.end ();
+         i++, it++)
+    {
+        StyleLines section;
+        if (!it->get_entry_list (section, __romaji_fund_table))
+            continue;
+
+		gtk_combo_box_text_append_text 
+			(GTK_COMBO_BOX_TEXT (omenu), _(it->get_title().c_str()));
+
+        if (check_list) {
+            if (it->get_file_name () == __config_romaji_theme_file) {
+                active_index = i + 2; // 2: user-define + default
+                check_list = false;
+			}
+		}
+    }
+
+    gtk_combo_box_set_active (GTK_COMBO_BOX (omenu), active_index);
+#else
     GtkWidget *menu = gtk_menu_new ();
     gtk_option_menu_set_menu (GTK_OPTION_MENU (omenu),
                               menu);
@@ -308,6 +384,7 @@ setup_romaji_theme_menu (GtkOptionMenu *
         G_OBJECT (omenu),
         (gpointer) (on_romaji_theme_menu_changed),
         NULL);
+#endif
 }
 
 static void
@@ -367,6 +444,11 @@ setup_default_romaji_table (void)
 static bool
 load_romaji_theme (void)
 {
+#if GTK_CHECK_VERSION(2, 24, 0)
+    GtkWidget *omenu = __widget_romaji_theme_menu;
+    gint idx = gtk_combo_box_get_active (GTK_COMBO_BOX (omenu));
+	gint theme_idx = idx - 2; // 2: user-defined + default
+#else
     GtkOptionMenu *omenu = GTK_OPTION_MENU (__widget_romaji_theme_menu);
     gint idx = gtk_option_menu_get_history (omenu);
     GtkWidget *menu = gtk_option_menu_get_menu (omenu);
@@ -378,6 +460,7 @@ load_romaji_theme (void)
 
     gint theme_idx = GPOINTER_TO_INT (g_object_get_data (G_OBJECT (menuitem),
                                                          INDEX_KEY));
+#endif
 
     // set new romaji table
     if (idx == ROMAJI_THEME_INDEX_USER_DEFINED) {
@@ -437,7 +520,7 @@ on_romaji_pseudo_ascii_mode_toggled (Gtk
 }
 
 static void
-on_romaji_theme_menu_changed (GtkOptionMenu *omenu, gpointer user_data)
+on_romaji_theme_menu_changed (GtkWidget *omenu, gpointer user_data)
 {
     bool success;
 
@@ -446,9 +529,15 @@ on_romaji_theme_menu_changed (GtkOptionM
             G_OBJECT (__widget_romaji_theme_menu),
             (gpointer) (on_romaji_theme_menu_changed),
             NULL);
+#if GTK_CHECK_VERSION(2, 24, 0)
+        gtk_combo_box_set_active (
+            GTK_COMBO_BOX (__widget_romaji_theme_menu),
+            gtk_combo_box_get_active (GTK_COMBO_BOX (omenu)));
+#else
         gtk_option_menu_set_history (
             GTK_OPTION_MENU (__widget_romaji_theme_menu),
-            gtk_option_menu_get_history (omenu));
+            gtk_option_menu_get_history (GTK_OPTION_MENU (omenu)));
+#endif
         g_signal_handlers_unblock_by_func (
             G_OBJECT (__widget_romaji_theme_menu),
             (gpointer) (on_romaji_theme_menu_changed),
@@ -492,9 +581,15 @@ static void
 on_table_editor_added_entry (ScimAnthyTableEditor *editor, gpointer data)
 {
     // change menu item to "User defined"
+#if GTK_CHECK_VERSION(2, 24, 0)
+    gtk_combo_box_set_active (
+        GTK_COMBO_BOX (__widget_romaji_theme_menu2),
+        ROMAJI_THEME_INDEX_USER_DEFINED);
+#else
     gtk_option_menu_set_history (
         GTK_OPTION_MENU (__widget_romaji_theme_menu2),
         ROMAJI_THEME_INDEX_USER_DEFINED);
+#endif
 
     __style_changed = true;
 }
@@ -515,9 +610,15 @@ static void
 on_table_editor_removed_entry (ScimAnthyTableEditor *editor, gpointer data)
 {
     // change menu item to "User deined"
+#if GTK_CHECK_VERSION(2, 24, 0)
+    gtk_combo_box_set_active (
+        GTK_COMBO_BOX (__widget_romaji_theme_menu2),
+        ROMAJI_THEME_INDEX_USER_DEFINED);
+#else
     gtk_option_menu_set_history (
         GTK_OPTION_MENU (__widget_romaji_theme_menu2),
         ROMAJI_THEME_INDEX_USER_DEFINED);
+#endif
 
     __style_changed = true;
 }
