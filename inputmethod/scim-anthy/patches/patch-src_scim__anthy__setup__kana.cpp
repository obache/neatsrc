$NetBSD$

* add gtk3+ support

--- src/scim_anthy_setup_kana.cpp.orig	2008-04-24 03:49:53.000000000 +0000
+++ src/scim_anthy_setup_kana.cpp
@@ -65,15 +65,15 @@ static GtkWidget *create_kana_window    
 static GtkWidget *create_nicola_window               (GtkWindow            *parent);
 
 static void     setup_kana_page                      (void);
-static void     setup_kana_layout_menu               (GtkOptionMenu        *omenu);
-static void     setup_nicola_layout_menu             (GtkOptionMenu        *omenu);
+static void     setup_kana_layout_menu               (GtkWidget *omenu);
+static void     setup_nicola_layout_menu             (GtkWidget *omenu);
 static void     setup_kana_window_value              (ScimAnthyTableEditor *editor);
 static void     setup_nicola_window_value            (ScimAnthyTableEditor *editor);
 
 static bool     load_kana_layout                     (void);
 static bool     load_nicola_layout                   (void);
 
-static void     on_kana_layout_menu_changed          (GtkOptionMenu        *omenu,
+static void     on_kana_layout_menu_changed          (GtkWidget *omenu,
                                                       gpointer              user_data);
 static void     on_kana_customize_button_clicked     (GtkWidget            *button,
                                                       gpointer              data);
@@ -85,7 +85,7 @@ static void     on_kana_table_editor_rem
                                                       gpointer              data);
 static void     on_kana_table_editor_removed_entry   (ScimAnthyTableEditor *editor,
                                                       gpointer              data);
-static void     on_nicola_layout_menu_changed        (GtkOptionMenu        *omenu,
+static void     on_nicola_layout_menu_changed        (GtkWidget *omenu,
                                                       gpointer              user_data);
 static void     on_nicola_customize_button_clicked   (GtkWidget            *button,
                                                       gpointer              data);
@@ -103,11 +103,19 @@ kana_page_create_ui (void)
 {
     GtkWidget *vbox;
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+    vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
+#else
     vbox = gtk_vbox_new (FALSE, 0);
+#endif
     gtk_widget_show (vbox);
 
     // JIS Kana Layout
+#if GTK_CHECK_VERSION(3, 0, 0)
+    GtkWidget *hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
+#else
     GtkWidget *hbox = gtk_hbox_new (FALSE, 0);
+#endif
     gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 4);
     gtk_widget_show (hbox);
 
@@ -122,7 +130,11 @@ kana_page_create_ui (void)
     gtk_widget_show (alignment);
 
     /* kana table */
+#if GTK_CHECK_VERSION(3, 0, 0)
+    hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
+#else
     hbox = gtk_hbox_new (FALSE, 0);
+#endif
     gtk_container_set_border_width (GTK_CONTAINER (hbox), 4);
     gtk_container_add (GTK_CONTAINER (alignment), hbox);
     gtk_widget_show(hbox);
@@ -131,7 +143,11 @@ kana_page_create_ui (void)
     gtk_box_pack_start (GTK_BOX (hbox), label, FALSE, FALSE, 2);
     gtk_widget_show (label);
 
+#if GTK_CHECK_VERSION(2, 24, 0)
+    GtkWidget *omenu = gtk_combo_box_text_new ();
+#else
     GtkWidget *omenu = gtk_option_menu_new ();
+#endif
     __widget_kana_layout_menu = omenu;
     g_signal_connect (G_OBJECT (omenu), "changed",
                       G_CALLBACK (on_kana_layout_menu_changed), NULL);
@@ -148,7 +164,11 @@ kana_page_create_ui (void)
 
 
     // Thumb Shift Layout
+#if GTK_CHECK_VERSION(3, 0, 0)
+    hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
+#else
     hbox = gtk_hbox_new (FALSE, 0);
+#endif
     gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 4);
     gtk_widget_show (hbox);
 
@@ -162,12 +182,20 @@ kana_page_create_ui (void)
     gtk_box_pack_start (GTK_BOX (vbox), alignment, FALSE, FALSE, 0);
     gtk_widget_show (alignment);
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+    GtkWidget *vbox2 = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
+#else
     GtkWidget *vbox2 = gtk_vbox_new (FALSE, 0);
+#endif
     gtk_container_add (GTK_CONTAINER (alignment), vbox2);
     gtk_widget_show (vbox2);
 
     /* nicola table */
+#if GTK_CHECK_VERSION(3, 0, 0)
+    hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
+#else
     hbox = gtk_hbox_new (FALSE, 0);
+#endif
     gtk_container_set_border_width (GTK_CONTAINER (hbox), 4);
     gtk_box_pack_start (GTK_BOX (vbox2), hbox, FALSE, FALSE, 0);
     gtk_widget_show(hbox);
@@ -176,7 +204,11 @@ kana_page_create_ui (void)
     gtk_box_pack_start (GTK_BOX (hbox), label, FALSE, FALSE, 2);
     gtk_widget_show (label);
 
+#if GTK_CHECK_VERSION(2, 24, 0)
+    omenu = gtk_combo_box_text_new ();
+#else
     omenu = gtk_option_menu_new ();
+#endif
     __widget_nicola_layout_menu = omenu;
     g_signal_connect (G_OBJECT (omenu), "changed",
                       G_CALLBACK (on_nicola_layout_menu_changed), NULL);
@@ -192,7 +224,11 @@ kana_page_create_ui (void)
     gtk_widget_show (button);
 
     /* thumb shift keys */
+#if GTK_CHECK_VERSION(3, 0, 0)
+    hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
+#else
     hbox = gtk_hbox_new (FALSE, 0);
+#endif
     gtk_box_pack_start (GTK_BOX (vbox2), hbox, FALSE, FALSE, 0);
     gtk_widget_show (hbox);
 
@@ -203,14 +239,14 @@ kana_page_create_ui (void)
     // left
     GtkWidget *widget = create_entry (SCIM_ANTHY_CONFIG_LEFT_THUMB_SHIFT_KEY,
                                       GTK_TABLE (table), 0);
-    gtk_entry_set_editable (GTK_ENTRY (widget), FALSE);
+    gtk_editable_set_editable (GTK_EDITABLE (widget), FALSE);
     widget = create_key_select_button (SCIM_ANTHY_CONFIG_LEFT_THUMB_SHIFT_KEY,
                                        GTK_TABLE (table), 0);
 
     // right
     widget = create_entry (SCIM_ANTHY_CONFIG_RIGHT_THUMB_SHIFT_KEY,
                            GTK_TABLE (table), 1);
-    gtk_entry_set_editable (GTK_ENTRY (widget), FALSE);
+    gtk_editable_set_editable (GTK_EDITABLE (widget), FALSE);
     widget = create_key_select_button (SCIM_ANTHY_CONFIG_RIGHT_THUMB_SHIFT_KEY,
                                        GTK_TABLE (table), 1);
 
@@ -270,27 +306,50 @@ create_kana_window (GtkWindow *parent)
                           _("Customize kana layout table"));
 
     // option menu area
+#if GTK_CHECK_VERSION(3, 0, 0)
+    GtkWidget *hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
+#else
     GtkWidget *hbox = gtk_hbox_new (FALSE, 0);
+#endif
     gtk_container_set_border_width (GTK_CONTAINER (hbox), 4);
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
     gtk_widget_show(hbox);
 
     GtkWidget *label = gtk_label_new_with_mnemonic (_("Layout _table:"));
     gtk_box_pack_start (GTK_BOX (hbox), label, FALSE, FALSE, 2);
     gtk_widget_show (label);
 
+#if GTK_CHECK_VERSION(2, 24, 0)
+    GtkWidget *omenu = gtk_combo_box_text_new ();
+#else
     GtkWidget *omenu = gtk_option_menu_new ();
+#endif
     __widget_kana_layout_menu2 = omenu;
     g_object_add_weak_pointer (G_OBJECT (omenu),
                                (gpointer*) &__widget_kana_layout_menu2);
     gtk_box_pack_start (GTK_BOX (hbox), omenu, FALSE, FALSE, 2);
-    setup_kana_layout_menu (GTK_OPTION_MENU (omenu));
+    setup_kana_layout_menu (omenu);
+#if GTK_CHECK_VERSION(2, 24, 0)
+    gtk_combo_box_set_active (
+		GTK_COMBO_BOX (omenu),
+		gtk_combo_box_get_active (GTK_COMBO_BOX (__widget_kana_layout_menu)));
+#else
     gtk_option_menu_set_history
         (GTK_OPTION_MENU (omenu),
          gtk_option_menu_get_history (
              GTK_OPTION_MENU (__widget_kana_layout_menu)));
+#endif
     gtk_widget_show (omenu);
 
     gtk_label_set_mnemonic_widget (GTK_LABEL(label), omenu);
@@ -342,27 +401,50 @@ create_nicola_window (GtkWindow *parent)
                           _("Customize thumb shift layout table"));
 
     // option menu area
+#if GTK_CHECK_VERSION(3, 0, 0)
+    GtkWidget *hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
+#else
     GtkWidget *hbox = gtk_hbox_new (FALSE, 0);
+#endif
     gtk_container_set_border_width (GTK_CONTAINER (hbox), 4);
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
     gtk_widget_show(hbox);
 
     GtkWidget *label = gtk_label_new_with_mnemonic (_("Layout _table:"));
     gtk_box_pack_start (GTK_BOX (hbox), label, FALSE, FALSE, 2);
     gtk_widget_show (label);
 
+#if GTK_CHECK_VERSION(2, 24, 0)
+    GtkWidget *omenu = gtk_combo_box_text_new ();
+#else
     GtkWidget *omenu = gtk_option_menu_new ();
+#endif
     __widget_nicola_layout_menu2 = omenu;
     g_object_add_weak_pointer (G_OBJECT (omenu),
                                (gpointer*) &__widget_nicola_layout_menu2);
     gtk_box_pack_start (GTK_BOX (hbox), omenu, FALSE, FALSE, 2);
-    setup_nicola_layout_menu (GTK_OPTION_MENU (omenu));
+    setup_nicola_layout_menu (omenu);
+#if GTK_CHECK_VERSION(2, 24, 0)
+    gtk_combo_box_set_active (
+		GTK_COMBO_BOX (omenu),
+		gtk_combo_box_get_active (GTK_COMBO_BOX (__widget_nicola_layout_menu)));
+#else
     gtk_option_menu_set_history
         (GTK_OPTION_MENU (omenu),
          gtk_option_menu_get_history (
              GTK_OPTION_MENU (__widget_nicola_layout_menu)));
+#endif
     gtk_widget_show (omenu);
 
     gtk_label_set_mnemonic_widget (GTK_LABEL(label), omenu);
@@ -397,13 +479,48 @@ create_nicola_window (GtkWindow *parent)
 static void
 setup_kana_page (void)
 {
-    setup_kana_layout_menu (GTK_OPTION_MENU (__widget_kana_layout_menu));
-    setup_nicola_layout_menu (GTK_OPTION_MENU (__widget_nicola_layout_menu));
+    setup_kana_layout_menu (__widget_kana_layout_menu);
+    setup_nicola_layout_menu (__widget_nicola_layout_menu);
 }
 
 static void
-setup_kana_layout_menu (GtkOptionMenu *omenu)
+setup_kana_layout_menu (GtkWidget *omenu)
 {
+#if GTK_CHECK_VERSION(2, 24, 0)
+    gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (omenu), _("User defined"));
+    gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (omenu), _("Default"));
+
+    gint active_index = KANA_LAYOUT_INDEX_DEFAULT;
+    bool check_list = false;
+    if (__config_kana_layout_file == __user_style_file.get_file_name ()) {
+        active_index = KANA_LAYOUT_INDEX_USER_DEFINED;
+    } else {
+        check_list = true;
+    }
+
+    StyleFiles::iterator it;
+    gint i;
+    for (i = 0, it = __style_list.begin ();
+         it != __style_list.end ();
+         i++, it++)
+    {
+        StyleLines section;
+        if (!it->get_entry_list (section, __kana_fund_table))
+            continue;
+
+		gtk_combo_box_text_append_text 
+			(GTK_COMBO_BOX_TEXT (omenu), _(it->get_title().c_str()));
+
+        if (check_list) {
+            if (it->get_file_name () == __config_kana_layout_file) {
+                active_index = i + 2; // 2: user-define + default
+                check_list = false;
+            }
+        }
+    }
+
+    gtk_combo_box_set_active (GTK_COMBO_BOX (omenu), active_index);
+#else
     GtkWidget *menu = gtk_menu_new ();
     gtk_option_menu_set_menu (GTK_OPTION_MENU (omenu),
                               menu);
@@ -466,11 +583,47 @@ setup_kana_layout_menu (GtkOptionMenu *o
         G_OBJECT (omenu),
         (gpointer) (on_kana_layout_menu_changed),
         NULL);
+#endif
 }
 
 static void
-setup_nicola_layout_menu (GtkOptionMenu *omenu)
+setup_nicola_layout_menu (GtkWidget *omenu)
 {
+#if GTK_CHECK_VERSION(2, 24, 0)
+	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (omenu), _("User defined"));
+	gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (omenu), _("Default"));
+
+    gint active_index = NICOLA_LAYOUT_INDEX_DEFAULT;
+    bool check_list = false;
+    if (__config_nicola_layout_file == __user_style_file.get_file_name ()) {
+        active_index = NICOLA_LAYOUT_INDEX_USER_DEFINED;
+    } else {
+        check_list = true;
+    }
+
+    StyleFiles::iterator it;
+    gint i;
+    for (i = 0, it = __style_list.begin ();
+         it != __style_list.end ();
+         i++, it++)
+    {
+        StyleLines section;
+        if (!it->get_entry_list (section, __nicola_fund_table))
+            continue;
+
+		gtk_combo_box_text_append_text (
+			GTK_COMBO_BOX_TEXT (omenu), _(it->get_title().c_str()));
+
+        if (check_list) {
+            if (it->get_file_name () == __config_nicola_layout_file) {
+                active_index = i + 2; // 2: user-define + default
+                check_list = false;
+            }
+        }
+    }
+
+    gtk_combo_box_set_active (GTK_COMBO_BOX (omenu), active_index);
+#else
     GtkWidget *menu = gtk_menu_new ();
     gtk_option_menu_set_menu (GTK_OPTION_MENU (omenu),
                               menu);
@@ -533,6 +686,7 @@ setup_nicola_layout_menu (GtkOptionMenu 
         G_OBJECT (omenu),
         (gpointer) (on_nicola_layout_menu_changed),
         NULL);
+#endif
 }
 
 static void
@@ -647,6 +801,10 @@ setup_default_nicola_table (void)
 static bool
 load_kana_layout (void)
 {
+#if GTK_CHECK_VERSION(2, 24, 0)
+    gint idx = gtk_combo_box_get_active (GTK_COMBO_BOX (__widget_kana_layout_menu));
+    gint theme_idx = idx - 2; // user definad and default
+#else
     GtkOptionMenu *omenu = GTK_OPTION_MENU (__widget_kana_layout_menu);
     gint idx = gtk_option_menu_get_history (omenu);
     GtkWidget *menu = gtk_option_menu_get_menu (omenu);
@@ -658,6 +816,7 @@ load_kana_layout (void)
 
     gint theme_idx = GPOINTER_TO_INT (g_object_get_data (G_OBJECT (menuitem),
                                                          INDEX_KEY));
+#endif
 
     // set new kana table
     if (idx == KANA_LAYOUT_INDEX_USER_DEFINED) {
@@ -707,6 +866,10 @@ load_kana_layout (void)
 static bool
 load_nicola_layout (void)
 {
+#if GTK_CHECK_VERSION(2, 24, 0)
+    gint idx = gtk_combo_box_get_active (GTK_COMBO_BOX (__widget_nicola_layout_menu));
+    gint theme_idx = idx - 2; // user definad and default
+#else
     GtkOptionMenu *omenu = GTK_OPTION_MENU (__widget_nicola_layout_menu);
     gint idx = gtk_option_menu_get_history (omenu);
     GtkWidget *menu = gtk_option_menu_get_menu (omenu);
@@ -718,6 +881,7 @@ load_nicola_layout (void)
 
     gint theme_idx = GPOINTER_TO_INT (g_object_get_data (G_OBJECT (menuitem),
                                                          INDEX_KEY));
+#endif
 
     // set new NICOLA table
     if (idx == NICOLA_LAYOUT_INDEX_USER_DEFINED) {
@@ -785,7 +949,7 @@ has_voiced_consonant (String str)
 }
 
 static void
-on_kana_layout_menu_changed (GtkOptionMenu *omenu, gpointer user_data)
+on_kana_layout_menu_changed (GtkWidget *omenu, gpointer user_data)
 {
     bool success;
 
@@ -794,9 +958,15 @@ on_kana_layout_menu_changed (GtkOptionMe
             G_OBJECT (__widget_kana_layout_menu),
             (gpointer) (on_kana_layout_menu_changed),
             NULL);
+#if GTK_CHECK_VERSION(2, 24, 0)
+        gtk_combo_box_set_active (
+            GTK_COMBO_BOX (__widget_kana_layout_menu),
+            gtk_combo_box_get_active (GTK_COMBO_BOX (omenu)));
+#else
         gtk_option_menu_set_history (
             GTK_OPTION_MENU (__widget_kana_layout_menu),
-            gtk_option_menu_get_history (omenu));
+            gtk_option_menu_get_history (GTK_OPTION_MENU (omenu)));
+#endif
         g_signal_handlers_unblock_by_func (
             G_OBJECT (__widget_kana_layout_menu),
             (gpointer) (on_kana_layout_menu_changed),
@@ -844,9 +1014,15 @@ static void
 on_kana_table_editor_added_entry (ScimAnthyTableEditor *editor, gpointer data)
 {
     // change menu item to "User defined"
+#if GTK_CHECK_VERSION(2, 24, 0)
+    gtk_combo_box_set_active (
+        GTK_COMBO_BOX (__widget_kana_layout_menu2),
+        KANA_LAYOUT_INDEX_USER_DEFINED);
+#else
     gtk_option_menu_set_history (
         GTK_OPTION_MENU (__widget_kana_layout_menu2),
         KANA_LAYOUT_INDEX_USER_DEFINED);
+#endif
 
     __style_changed = true;
 }
@@ -865,15 +1041,21 @@ static void
 on_kana_table_editor_removed_entry (ScimAnthyTableEditor *editor, gpointer data)
 {
     // change menu item to "User deined"
+#if GTK_CHECK_VERSION(2, 24, 0)
+    gtk_combo_box_set_active (
+        GTK_COMBO_BOX (__widget_kana_layout_menu2),
+        KANA_LAYOUT_INDEX_USER_DEFINED);
+#else
     gtk_option_menu_set_history (
         GTK_OPTION_MENU (__widget_kana_layout_menu2),
         KANA_LAYOUT_INDEX_USER_DEFINED);
+#endif
 
     __style_changed = true;
 }
 
 static void
-on_nicola_layout_menu_changed (GtkOptionMenu *omenu, gpointer user_data)
+on_nicola_layout_menu_changed (GtkWidget *omenu, gpointer user_data)
 {
     bool success;
 
@@ -882,9 +1064,15 @@ on_nicola_layout_menu_changed (GtkOption
             G_OBJECT (__widget_nicola_layout_menu),
             (gpointer) (on_nicola_layout_menu_changed),
             NULL);
+#if GTK_CHECK_VERSION(2, 24, 0)
+        gtk_combo_box_set_active (
+            GTK_COMBO_BOX (__widget_nicola_layout_menu),
+            gtk_combo_box_get_active (GTK_COMBO_BOX (omenu)));
+#else
         gtk_option_menu_set_history (
             GTK_OPTION_MENU (__widget_nicola_layout_menu),
-            gtk_option_menu_get_history (omenu));
+            gtk_option_menu_get_history (GTK_OPTION_MENU (omenu)));
+#endif 
         g_signal_handlers_unblock_by_func (
             G_OBJECT (__widget_nicola_layout_menu),
             (gpointer) (on_nicola_layout_menu_changed),
@@ -928,9 +1116,15 @@ static void
 on_nicola_table_editor_added_entry (ScimAnthyTableEditor *editor, gpointer data)
 {
     // change menu item to "User defined"
+#if GTK_CHECK_VERSION(2, 24, 0)
+    gtk_combo_box_set_active (
+        GTK_COMBO_BOX (__widget_nicola_layout_menu2),
+        NICOLA_LAYOUT_INDEX_USER_DEFINED);
+#else
     gtk_option_menu_set_history (
         GTK_OPTION_MENU (__widget_nicola_layout_menu2),
         NICOLA_LAYOUT_INDEX_USER_DEFINED);
+#endif
 
     __style_changed = true;
 }
@@ -949,9 +1143,15 @@ static void
 on_nicola_table_editor_removed_entry (ScimAnthyTableEditor *editor, gpointer data)
 {
     // change menu item to "User deined"
+#if GTK_CHECK_VERSION(2, 24, 0)
+    gtk_combo_box_set_active (
+        GTK_COMBO_BOX (__widget_nicola_layout_menu2),
+        NICOLA_LAYOUT_INDEX_USER_DEFINED);
+#else
     gtk_option_menu_set_history (
         GTK_OPTION_MENU (__widget_nicola_layout_menu2),
         NICOLA_LAYOUT_INDEX_USER_DEFINED);
+#endif
 
     __style_changed = true;
 }
