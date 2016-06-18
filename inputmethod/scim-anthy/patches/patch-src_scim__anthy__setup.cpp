$NetBSD$

* add gtk3+ support

--- src/scim_anthy_setup.cpp.orig	2009-01-15 01:44:12.000000000 +0000
+++ src/scim_anthy_setup.cpp
@@ -174,7 +174,10 @@ static GtkWidget   * __widget_key_filter
 static GtkWidget   * __widget_key_theme_menu        = NULL;
 static GtkWidget   * __widget_key_list_view         = NULL;
 static GtkWidget   * __widget_choose_keys_button    = NULL;
+#if GTK_CHECK_VERSION(3, 0, 0)
+#else
 static GtkTooltips * __widget_tooltips              = NULL;
+#endif
 
 static String __config_key_theme      = SCIM_ANTHY_CONFIG_KEY_THEME_DEFAULT;
 static String __config_key_theme_file = SCIM_ANTHY_CONFIG_KEY_THEME_FILE_DEFAULT;
@@ -295,7 +298,7 @@ static ComboConfigCandidate preedit_styl
 };
 
 
-static void     setup_key_theme_menu              (GtkOptionMenu *omenu);
+static void     setup_key_theme_menu              (GtkWidget *omenu);
 static void     setup_widget_value                (void);
 
 static void     on_default_editable_changed       (GtkEditable      *editable,
@@ -308,15 +311,15 @@ static void     on_default_key_selection
                                                    gpointer          user_data);
 static void     on_default_combo_changed          (GtkEditable      *editable,
                                                    gpointer          user_data);
-static void     on_default_option_menu_changed    (GtkOptionMenu    *omenu,
+static void     on_default_option_menu_changed    (GtkWidget        *omenu,
                                                    gpointer          user_data);
-static void     on_preedit_style_menu_changed     (GtkOptionMenu    *omenu,
+static void     on_preedit_style_menu_changed     (GtkWidget        *omenu,
                                                    gpointer          user_data);
 static void     on_key_filter_selection_clicked   (GtkButton        *button,
                                                    gpointer          user_data);
 static void     on_dict_menu_label_toggled        (GtkToggleButton  *togglebutton,
                                                    gpointer          user_data);
-static void     on_key_category_menu_changed      (GtkOptionMenu    *omenu,
+static void     on_key_category_menu_changed      (GtkWidget        *omenu,
                                                    gpointer          user_data);
 static gboolean on_key_list_view_key_press        (GtkWidget        *widget,
                                                    GdkEventKey      *event,
@@ -324,7 +327,7 @@ static gboolean on_key_list_view_key_pre
 static gboolean on_key_list_view_button_press     (GtkWidget        *widget,
                                                    GdkEventButton   *event,
                                                    gpointer          user_data);
-static void     on_key_theme_menu_changed         (GtkOptionMenu    *omenu,
+static void     on_key_theme_menu_changed         (GtkWidget        *omenu,
                                                    gpointer          user_data);
 static void     on_key_list_selection_changed     (GtkTreeSelection *selection,
                                                    gpointer          data);
@@ -364,11 +367,19 @@ create_check_button (const char *config_
                       entry);
     gtk_widget_show (GTK_WIDGET (entry->widget));
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+#else
     if (!__widget_tooltips)
         __widget_tooltips = gtk_tooltips_new();
+#endif
     if (entry->tooltip)
+#if GTK_CHECK_VERSION(3, 0, 0)
+        gtk_widget_set_tooltip_text (GTK_WIDGET (entry->widget),
+                              _(entry->tooltip));
+#else
         gtk_tooltips_set_tip (__widget_tooltips, GTK_WIDGET (entry->widget),
                               _(entry->tooltip), NULL);
+#endif
 
     return GTK_WIDGET (entry->widget);
 }
@@ -389,7 +400,11 @@ create_spin_button (const char *config_k
                       4, 4);
     gtk_widget_show (GTK_WIDGET (label));
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+    GtkWidget *hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
+#else
     GtkWidget *hbox = gtk_hbox_new (FALSE, 0);
+#endif
     gtk_table_attach (GTK_TABLE (table), GTK_WIDGET (hbox),
                       1, 2, idx, idx + 1,
                       (GtkAttachOptions) GTK_FILL,
@@ -417,11 +432,18 @@ create_spin_button (const char *config_k
         gtk_widget_show (GTK_WIDGET (label));
     }
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+#else
     if (!__widget_tooltips)
         __widget_tooltips = gtk_tooltips_new();
+#endif
     if (entry->tooltip)
+#if GTK_CHECK_VERSION(3, 0, 0)
+        gtk_widget_set_tooltip_text (GTK_WIDGET (entry->widget), _(entry->tooltip));
+#else
         gtk_tooltips_set_tip (__widget_tooltips, GTK_WIDGET (entry->widget),
                               _(entry->tooltip), NULL);
+#endif
 
     return GTK_WIDGET (entry->widget);
 }
@@ -453,11 +475,18 @@ create_entry (const char *config_key, Gt
                       (GtkAttachOptions) (GTK_FILL|GTK_EXPAND),
                       (GtkAttachOptions) (GTK_FILL), 4, 4);
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+#else
     if (!__widget_tooltips)
         __widget_tooltips = gtk_tooltips_new();
+#endif
     if (entry->tooltip)
+#if GTK_CHECK_VERSION(3, 0, 0)
+        gtk_widget_set_tooltip_text (GTK_WIDGET (entry->widget), _(entry->tooltip));
+#else
         gtk_tooltips_set_tip (__widget_tooltips, GTK_WIDGET (entry->widget),
                               _(entry->tooltip), NULL);
+#endif
 
     return GTK_WIDGET (entry->widget);
 }
@@ -480,12 +509,31 @@ create_combo (const char *config_key, gp
                       (GtkAttachOptions) (GTK_FILL), 4, 4);
     gtk_widget_show (label);
 
+#if GTK_CHECK_VERSION(2, 24, 0)
+    entry->widget = gtk_combo_box_text_new_with_entry ();
+    GtkWidget *combo_box_entry = gtk_bin_get_child (GTK_BIN (entry->widget));
+    gtk_label_set_mnemonic_widget (GTK_LABEL (label), combo_box_entry);
+    gtk_editable_set_editable (GTK_EDITABLE (combo_box_entry), FALSE);
+
+    gtk_widget_show (GTK_WIDGET (entry->widget));
+    gtk_table_attach (GTK_TABLE (table), GTK_WIDGET (entry->widget),
+                      1, 2, idx, idx + 1,
+                      (GtkAttachOptions) (GTK_FILL|GTK_EXPAND),
+                      (GtkAttachOptions) (GTK_FILL), 4, 4);
+    g_object_set_data (G_OBJECT (combo_box_entry),
+                       DATA_POINTER_KEY,
+                       (gpointer) candidates_p);
+
+    g_signal_connect (G_OBJECT (combo_box_entry), "changed",
+                      G_CALLBACK (on_default_combo_changed),
+                      entry);
+#else
     entry->widget = gtk_combo_new ();
     gtk_label_set_mnemonic_widget (GTK_LABEL (label),
                                    GTK_COMBO (entry->widget)->entry);
     gtk_combo_set_value_in_list (GTK_COMBO (entry->widget), TRUE, FALSE);
     gtk_combo_set_case_sensitive (GTK_COMBO (entry->widget), TRUE);
-    gtk_entry_set_editable (GTK_ENTRY (GTK_COMBO (entry->widget)->entry),
+    gtk_editable_set_editable (GTK_EDITABLE (GTK_COMBO (entry->widget)->entry),
                             FALSE);
     gtk_widget_show (GTK_WIDGET (entry->widget));
     gtk_table_attach (GTK_TABLE (table), GTK_WIDGET (entry->widget),
@@ -499,13 +547,22 @@ create_combo (const char *config_key, gp
     g_signal_connect ((gpointer) GTK_COMBO (entry->widget)->entry, "changed",
                       G_CALLBACK (on_default_combo_changed),
                       entry);
+#endif
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+#else
     if (!__widget_tooltips)
         __widget_tooltips = gtk_tooltips_new();
+#endif
     if (entry->tooltip)
+#if GTK_CHECK_VERSION(3, 0, 0)
+        gtk_widget_set_tooltip_text (
+            gtk_bin_get_child (GTK_BIN (entry->widget)), _(entry->tooltip));
+#else
         gtk_tooltips_set_tip (__widget_tooltips,
                               GTK_WIDGET (GTK_COMBO (entry->widget)->entry),
                               _(entry->tooltip), NULL);
+#endif
 
     return GTK_WIDGET (entry->widget);
 }
@@ -528,6 +585,29 @@ create_option_menu (const char *config_k
                       (GtkAttachOptions) (GTK_FILL), 4, 4);
     gtk_widget_show (label);
 
+#if GTK_CHECK_VERSION(2, 24, 0)
+    entry->widget = gtk_combo_box_text_new ();
+    gtk_label_set_mnemonic_widget (GTK_LABEL (label),
+                                   GTK_WIDGET (entry->widget));
+    gtk_widget_show (GTK_WIDGET (entry->widget));
+    gtk_table_attach (GTK_TABLE (table), GTK_WIDGET (entry->widget),
+                      1, 2, idx, idx + 1,
+                      (GtkAttachOptions) (GTK_FILL),
+                      (GtkAttachOptions) (GTK_FILL), 4, 4);
+    g_object_set_data (G_OBJECT (entry->widget),
+                       DATA_POINTER_KEY,
+                       (gpointer) candidates_p);
+
+    for (unsigned int i = 0; data[i].label; i++) {
+        gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (entry->widget), _(data[i].label));
+    }
+
+    gtk_combo_box_set_active (GTK_COMBO_BOX (entry->widget), 0);
+
+    g_signal_connect (G_OBJECT (entry->widget), "changed",
+                      G_CALLBACK (on_default_option_menu_changed),
+                      entry);
+#else
     entry->widget = gtk_option_menu_new ();
     gtk_label_set_mnemonic_widget (GTK_LABEL (label),
                                    GTK_WIDGET (entry->widget));
@@ -555,12 +635,20 @@ create_option_menu (const char *config_k
     g_signal_connect ((gpointer) GTK_OPTION_MENU (entry->widget), "changed",
                       G_CALLBACK (on_default_option_menu_changed),
                       entry);
+#endif
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+#else
     if (!__widget_tooltips)
         __widget_tooltips = gtk_tooltips_new();
+#endif
     if (entry->tooltip)
+#if GTK_CHECK_VERSION(3, 0, 0)
+        gtk_widget_set_tooltip_text (GTK_WIDGET (entry->widget), _(entry->tooltip));
+#else
         gtk_tooltips_set_tip (__widget_tooltips, GTK_WIDGET (entry->widget),
                               _(entry->tooltip), NULL);
+#endif
 
     return GTK_WIDGET (entry->widget);
 }
@@ -590,7 +678,11 @@ create_color_button (const char *config_
     if (!entry)
         return NULL;
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+    GtkWidget *hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
+#else
     GtkWidget *hbox = gtk_hbox_new (FALSE, 0);
+#endif
     gtk_container_set_border_width (GTK_CONTAINER (hbox), 4);
     gtk_widget_show (hbox);
 
@@ -614,11 +706,18 @@ create_color_button (const char *config_
         gtk_label_set_mnemonic_widget (GTK_LABEL (label),
                                        GTK_WIDGET (entry->widget));
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+#else
     if (!__widget_tooltips)
         __widget_tooltips = gtk_tooltips_new();
+#endif
     if (entry->tooltip)
+#if GTK_CHECK_VERSION(3, 0, 0)
+        gtk_widget_set_tooltip_text (GTK_WIDGET (entry->widget), _(entry->tooltip));
+#else
         gtk_tooltips_set_tip (__widget_tooltips, GTK_WIDGET (entry->widget),
                               _(entry->tooltip), NULL);
+#endif
 
     return hbox;
 }
@@ -701,9 +800,15 @@ key_list_view_popup_key_selection (GtkTr
                 gtk_list_store_set (GTK_LIST_STORE (model), &iter,
                                     COLUMN_VALUE, data->value.c_str(),
                                     -1);
+#if GTK_CHECK_VERSION(2, 24, 0)
+                gtk_combo_box_set_active(
+                    GTK_COMBO_BOX (__widget_key_theme_menu),
+                    KEY_THEME_INDEX_USER_DEFINED);
+#else
                 gtk_option_menu_set_history (
                     GTK_OPTION_MENU (__widget_key_theme_menu),
                     KEY_THEME_INDEX_USER_DEFINED);
+#endif
                 data->changed = true;
                 __config_changed = true;
             }
@@ -718,7 +823,11 @@ create_common_page (void)
 {
     GtkWidget *vbox, *table, *widget;
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+    vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
+#else
     vbox = gtk_vbox_new (FALSE, 0);
+#endif
     gtk_widget_show (vbox);
 
     table = gtk_table_new (7, 2, FALSE);
@@ -753,7 +862,11 @@ create_symbols_page (void)
 {
     GtkWidget *vbox, *table, *widget;
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+    vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
+#else
     vbox = gtk_vbox_new (FALSE, 0);
+#endif
     gtk_widget_show (vbox);
 
     table = gtk_table_new (7, 2, FALSE);
@@ -793,10 +906,18 @@ create_keyboard_page (void)
 {
     GtkWidget *vbox, *hbox;
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+    vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
+#else
     vbox = gtk_vbox_new (FALSE, 0);
+#endif
     gtk_widget_show (vbox);
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+    hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
+#else
     hbox = gtk_hbox_new (FALSE, 0);
+#endif
     gtk_container_set_border_width (GTK_CONTAINER (hbox), 4);
     gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);
     gtk_widget_show(hbox);
@@ -806,6 +927,28 @@ create_keyboard_page (void)
     gtk_box_pack_start (GTK_BOX (hbox), label, FALSE, FALSE, 2);
     gtk_widget_show (label);
 
+#if GTK_CHECK_VERSION(2, 24, 0)
+    GtkWidget *omenu = gtk_combo_box_text_new ();
+    __widget_key_categories_menu = omenu;
+    gtk_box_pack_start (GTK_BOX (hbox), omenu, FALSE, FALSE, 2);
+    gtk_widget_show (omenu);
+
+    gtk_label_set_mnemonic_widget (GTK_LABEL (label), omenu);
+
+    gtk_combo_box_text_append_text
+        (GTK_COMBO_BOX_TEXT (omenu),
+        _("All"));
+
+    for (unsigned int i = 0; i < __key_conf_pages_num; i++) {
+        gtk_combo_box_text_append_text
+            (GTK_COMBO_BOX_TEXT (omenu),
+            _(__key_conf_pages[i].label));
+    }
+
+    gtk_combo_box_text_append_text
+        (GTK_COMBO_BOX_TEXT (omenu),
+        _("Search by key"));
+#else
     GtkWidget *omenu = gtk_option_menu_new ();
     __widget_key_categories_menu = omenu;
     gtk_box_pack_start (GTK_BOX (hbox), omenu, FALSE, FALSE, 2);
@@ -833,10 +976,11 @@ create_keyboard_page (void)
 
     gtk_option_menu_set_menu (GTK_OPTION_MENU (omenu), menu);
     gtk_widget_show (menu);
+#endif
 
     GtkWidget *entry = gtk_entry_new ();
     __widget_key_filter = entry;
-    gtk_entry_set_editable (GTK_ENTRY (entry), FALSE);
+    gtk_editable_set_editable (GTK_EDITABLE (entry), FALSE);
     gtk_box_pack_start (GTK_BOX (hbox), entry, TRUE, TRUE, 2);
     gtk_widget_show(entry);
 
@@ -905,7 +1049,11 @@ create_keyboard_page (void)
     g_signal_connect (G_OBJECT (selection), "changed",
                       G_CALLBACK (on_key_list_selection_changed), treeview);
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+    hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
+#else
     hbox = gtk_hbox_new (FALSE, 0);
+#endif
     gtk_container_set_border_width (GTK_CONTAINER (hbox), 4);
     gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);
     gtk_widget_show(hbox);
@@ -915,7 +1063,11 @@ create_keyboard_page (void)
     gtk_box_pack_start (GTK_BOX (hbox), label, FALSE, FALSE, 2);
     gtk_widget_show (label);
 
+#if GTK_CHECK_VERSION(2, 24, 0)
+    omenu = gtk_combo_box_text_new ();
+#else
     omenu = gtk_option_menu_new ();
+#endif
     __widget_key_theme_menu = omenu;
     g_signal_connect (G_OBJECT (omenu), "changed",
                       G_CALLBACK (on_key_theme_menu_changed), NULL);
@@ -945,10 +1097,18 @@ create_learning_page ()
     GtkWidget *vbox, *vbox2, *hbox, *alignment, *table;
     GtkWidget *widget, *label;
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+    vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
+#else
     vbox = gtk_vbox_new (FALSE, 0);
+#endif
     gtk_widget_show (vbox);
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+    hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
+#else
     hbox = gtk_hbox_new (FALSE, 0);
+#endif
     gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 4);
     gtk_widget_show (hbox);
 
@@ -962,7 +1122,11 @@ create_learning_page ()
     gtk_box_pack_start (GTK_BOX (vbox), alignment, FALSE, FALSE, 0);
     gtk_widget_show (alignment);
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+    vbox2 = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
+#else
     vbox2 = gtk_vbox_new (FALSE, 0);
+#endif
     gtk_container_add (GTK_CONTAINER (alignment), vbox2);
     gtk_widget_show (vbox2);
 
@@ -975,7 +1139,11 @@ create_learning_page ()
     gtk_box_pack_start (GTK_BOX (vbox2), widget, FALSE, FALSE, 4);
 
     /* key preference */
+#if GTK_CHECK_VERSION(3, 0, 0)
+    hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
+#else
     hbox = gtk_hbox_new (FALSE, 0);
+#endif
     gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 4);
     gtk_widget_show (hbox);
 
@@ -1008,7 +1176,7 @@ create_learning_page ()
     {
         StringConfigData *entry = entries[i];
         widget = create_entry (entry->key, GTK_TABLE (table), i);
-        gtk_entry_set_editable (GTK_ENTRY (widget), FALSE);
+        gtk_editable_set_editable (GTK_EDITABLE (widget), FALSE);
         create_key_select_button (entry->key, GTK_TABLE (table), i);
     }
 
@@ -1020,7 +1188,11 @@ create_prediction_page ()
 {
     GtkWidget *vbox, *widget;
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+    vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
+#else
     vbox = gtk_vbox_new (FALSE, 0);
+#endif
     gtk_widget_show (vbox);
 
     /* predict while inputting */
@@ -1084,7 +1256,11 @@ create_candidates_window_page (void)
 {
     GtkWidget *vbox, *widget, *table;
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+    vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
+#else
     vbox = gtk_vbox_new (FALSE, 0);
+#endif
     gtk_widget_show (vbox);
 
     /* show candidates label */
@@ -1115,7 +1291,11 @@ create_toolbar_page (void)
 {
     GtkWidget *vbox, *hbox, *label, *widget;
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+    vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
+#else
     vbox = gtk_vbox_new (FALSE, 0);
+#endif
     gtk_widget_show (vbox);
 
     /* show/hide toolbar label */
@@ -1141,7 +1321,11 @@ create_toolbar_page (void)
                       NULL);
     gtk_box_pack_start (GTK_BOX (vbox), widget, FALSE, FALSE, 2);
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+    hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
+#else
     hbox = gtk_hbox_new (FALSE, 0);
+#endif
     gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 2);
     gtk_widget_show (hbox);
     label = gtk_label_new ("    ");
@@ -1166,7 +1350,11 @@ create_appearance_page (void)
 {
     GtkWidget *vbox, *table, *omenu, *widget, *hbox; 
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+    vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
+#else
     vbox = gtk_vbox_new (FALSE, 0);
+#endif
     gtk_widget_show (vbox);
 
     table = gtk_table_new (2, 3, FALSE);
@@ -1178,7 +1366,11 @@ create_appearance_page (void)
                                 &preedit_style, GTK_TABLE (table), 0);
 
     /* preedit color */
+#if GTK_CHECK_VERSION(3, 0, 0)
+    hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
+#else
     hbox = gtk_hbox_new (FALSE, 0);
+#endif
     gtk_widget_show (hbox);
     widget = create_color_button (SCIM_ANTHY_CONFIG_PREEDIT_FG_COLOR);
     gtk_box_pack_start (GTK_BOX (hbox), widget, FALSE, FALSE, 0);
@@ -1187,15 +1379,24 @@ create_appearance_page (void)
                       (GtkAttachOptions) (GTK_FILL), 4, 4);
     gtk_widget_set_sensitive (hbox, FALSE);
 
+#if GTK_CHECK_VERSION(2, 24, 0)
+    g_signal_connect (G_OBJECT (omenu), "changed",
+                      G_CALLBACK (on_preedit_style_menu_changed), hbox);
+#else
     g_signal_connect ((gpointer) GTK_OPTION_MENU (omenu), "changed",
                       G_CALLBACK (on_preedit_style_menu_changed), hbox);
+#endif
 
     /* conversion style */
     omenu = create_option_menu (SCIM_ANTHY_CONFIG_CONVERSION_STYLE,
                                 &preedit_style, GTK_TABLE (table), 1);
 
     /* conversion color */
+#if GTK_CHECK_VERSION(3, 0, 0)
+    hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
+#else
     hbox = gtk_hbox_new (FALSE, 0);
+#endif
     gtk_widget_show (hbox);
     widget = create_color_button (SCIM_ANTHY_CONFIG_CONVERSION_FG_COLOR);
     gtk_box_pack_start (GTK_BOX (hbox), widget, FALSE, FALSE, 0);
@@ -1204,15 +1405,24 @@ create_appearance_page (void)
                       (GtkAttachOptions) (GTK_FILL), 4, 4);
     gtk_widget_set_sensitive (hbox, FALSE);
 
+#if GTK_CHECK_VERSION(2, 24, 0)
+    g_signal_connect (G_OBJECT (omenu), "changed",
+                      G_CALLBACK (on_preedit_style_menu_changed), hbox);
+#else
     g_signal_connect ((gpointer) GTK_OPTION_MENU (omenu), "changed",
                       G_CALLBACK (on_preedit_style_menu_changed), hbox);
+#endif
 
     /* selected segment style */
     omenu = create_option_menu (SCIM_ANTHY_CONFIG_SELECTED_SEGMENT_STYLE,
                                 &preedit_style, GTK_TABLE (table), 2);
 
     /* selected segment color */
+#if GTK_CHECK_VERSION(3, 0, 0)
+    hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
+#else
     hbox = gtk_hbox_new (FALSE, 0);
+#endif
     gtk_widget_show (hbox);
     widget = create_color_button (SCIM_ANTHY_CONFIG_SELECTED_SEGMENT_FG_COLOR);
     gtk_box_pack_start (GTK_BOX (hbox), widget, FALSE, FALSE, 0);
@@ -1221,8 +1431,13 @@ create_appearance_page (void)
                       (GtkAttachOptions) (GTK_FILL), 4, 4);
     gtk_widget_set_sensitive (hbox, FALSE);
 
+#if GTK_CHECK_VERSION(2, 24, 0)
+    g_signal_connect (G_OBJECT (omenu), "changed",
+                      G_CALLBACK (on_preedit_style_menu_changed), hbox);
+#else
     g_signal_connect ((gpointer) GTK_OPTION_MENU (omenu), "changed",
                       G_CALLBACK (on_preedit_style_menu_changed), hbox);
+#endif
 
     return vbox;
 }
@@ -1233,7 +1448,11 @@ create_about_page ()
     GtkWidget *vbox, *label;
     gchar str[256];
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+    vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
+#else
     vbox = gtk_vbox_new (FALSE, 0);
+#endif
     gtk_widget_show (vbox);
 
     g_snprintf (
@@ -1355,8 +1574,24 @@ create_setup_window (void)
 }
 
 static void
-setup_combo_value (GtkCombo *combo, const String & str)
+setup_combo_value (GtkWidget *combo, const String & str)
 {
+#if GTK_CHECK_VERSION(2, 24, 0)
+    ComboConfigCandidate *data
+        = static_cast<ComboConfigCandidate*>
+        (g_object_get_data (G_OBJECT (gtk_bin_get_child (GTK_BIN (combo))),
+                            DATA_POINTER_KEY));
+
+    gint default_index = -1;
+    for (unsigned int i = 0; data[i].label; i++) {
+        gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (combo), _(data[i].label));
+        if (!strcmp (data[i].data, str.c_str ()))
+            default_index = i;
+    }
+
+    if (default_index != -1)
+        gtk_combo_box_set_active (GTK_COMBO_BOX (combo), default_index);
+#else
     GList *list = NULL;
     const char *defval = NULL;
 
@@ -1371,15 +1606,16 @@ setup_combo_value (GtkCombo *combo, cons
             defval = _(data[i].label);
     }
 
-    gtk_combo_set_popdown_strings (combo, list);
+    gtk_combo_set_popdown_strings (GTK_COMBO (combo), list);
     g_list_free (list);
 
     if (defval)
-        gtk_entry_set_text (GTK_ENTRY (combo->entry), defval);
+        gtk_entry_set_text (GTK_ENTRY (GTK_COMBO(combo)->entry), defval);
+#endif
 }
 
 static void
-setup_option_menu_value (GtkOptionMenu *omenu, const String & str)
+setup_option_menu_value (GtkWidget *omenu, const String & str)
 {
     ComboConfigCandidate *data
         = static_cast<ComboConfigCandidate*>
@@ -1387,15 +1623,55 @@ setup_option_menu_value (GtkOptionMenu *
 
     for (unsigned int i = 0; data[i].label; i++) {
         if (!strcmp (data[i].data, str.c_str ())) {
-            gtk_option_menu_set_history (omenu, i);
+#if GTK_CHECK_VERSION(2, 24, 0)
+            gtk_combo_box_set_active (GTK_COMBO_BOX (omenu), i);
+#else
+            gtk_option_menu_set_history (GTK_OPTION_MENU (omenu), i);
+#endif
             return;
         }
     }
 }
 
 static void
-setup_key_theme_menu (GtkOptionMenu *omenu)
+setup_key_theme_menu (GtkWidget *omenu)
 {
+#if GTK_CHECK_VERSION(2, 24, 0)
+    gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (omenu), _("User defined"));
+    gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (omenu), _("Default"));
+
+    gint active_index = KEY_THEME_INDEX_DEFAULT;
+    bool check_list = false;
+    if (__config_key_theme_file == __user_style_file.get_file_name () ||
+        __config_key_theme      == __user_style_file.get_title ()) {
+        active_index = KEY_THEME_INDEX_USER_DEFINED;
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
+        const char *section_name = "KeyBindings";
+        StyleLines section;
+        if (!it->get_entry_list (section, section_name))
+            continue;
+
+        gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT (omenu), _(it->get_title().c_str()));
+
+        if (check_list) {
+            if (it->get_file_name () == __config_key_theme_file) {
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
@@ -1459,6 +1735,7 @@ setup_key_theme_menu (GtkOptionMenu *ome
     g_signal_handlers_unblock_by_func (G_OBJECT (omenu),
                                        (gpointer) (on_key_theme_menu_changed),
                                        NULL);
+#endif
 }
 
 static void
@@ -1480,12 +1757,22 @@ setup_widget_value (void)
 
     for (unsigned int i = 0; config_string_common[i].key; i++) {
         StringConfigData &entry = config_string_common[i];
+#if GTK_CHECK_VERSION(2, 24, 0)
+        if (entry.widget && GTK_IS_COMBO_BOX (entry.widget)) {
+            if (gtk_combo_box_get_has_entry (GTK_COMBO_BOX (entry.widget))) {
+                setup_combo_value (GTK_WIDGET (entry.widget), entry.value);
+            } else {
+                setup_option_menu_value (GTK_WIDGET (entry.widget), entry.value);
+            }
+        }
+#else
         if (entry.widget && GTK_IS_OPTION_MENU (entry.widget)) {
-            setup_option_menu_value (GTK_OPTION_MENU (entry.widget),
-                                     entry.value);
+            setup_option_menu_value (GTK_WIDGET (entry.widget), entry.value);
         } else if (entry.widget && GTK_IS_COMBO (entry.widget)) {
-            setup_combo_value (GTK_COMBO (entry.widget), entry.value);
-        } else if (entry.widget && GTK_IS_ENTRY (entry.widget)) {
+            setup_combo_value (GTK_WIDGET (entry.widget), entry.value);
+        }
+#endif
+        else if (entry.widget && GTK_IS_ENTRY (entry.widget)) {
             gtk_entry_set_text (GTK_ENTRY (entry.widget),
                                 entry.value.c_str ());
         }
@@ -1509,9 +1796,15 @@ setup_widget_value (void)
         }
     }
 
+#if GTK_CHECK_VERSION(2, 24, 0)
+    gtk_combo_box_set_active
+        (GTK_COMBO_BOX (__widget_key_categories_menu),
+         KEY_CATEGORY_INDEX_ALL);
+#else
     gtk_option_menu_set_history
         (GTK_OPTION_MENU (__widget_key_categories_menu),
          KEY_CATEGORY_INDEX_ALL);
+#endif
     GtkTreeView *treeview = GTK_TREE_VIEW (__widget_key_list_view);
     GtkListStore *store = GTK_LIST_STORE (gtk_tree_view_get_model (treeview));
     gtk_list_store_clear (store);
@@ -1521,7 +1814,7 @@ setup_widget_value (void)
     gtk_widget_set_sensitive (__widget_key_filter_button, FALSE);
 
     // setup option menu
-    setup_key_theme_menu (GTK_OPTION_MENU (__widget_key_theme_menu));
+    setup_key_theme_menu (__widget_key_theme_menu);
 }
 
 bool operator < (const StyleFile &left, const StyleFile &right)
@@ -1822,7 +2115,7 @@ on_default_combo_changed (GtkEditable *e
 }
 
 static void
-on_default_option_menu_changed (GtkOptionMenu *omenu, gpointer user_data)
+on_default_option_menu_changed (GtkWidget *omenu, gpointer user_data)
 {
     StringConfigData *entry = static_cast<StringConfigData*> (user_data);
     ComboConfigCandidate *data = static_cast<ComboConfigCandidate*>
@@ -1833,7 +2126,11 @@ on_default_option_menu_changed (GtkOptio
     if (!data) return;
 
     for (int i = 0; data[i].label; i++) {
-        if (i == gtk_option_menu_get_history (omenu)) {
+#if GTK_CHECK_VERSION(2, 24, 0)
+        if (i == gtk_combo_box_get_active (GTK_COMBO_BOX (omenu))) {
+#else
+        if (i == gtk_option_menu_get_history (GTK_OPTION_MENU (omenu))) {
+#endif
             entry->value     = data[i].data;
             entry->changed   = true;
             __config_changed = true;
@@ -1843,11 +2140,15 @@ on_default_option_menu_changed (GtkOptio
 }
 
 static void
-on_preedit_style_menu_changed (GtkOptionMenu *omenu, gpointer user_data)
+on_preedit_style_menu_changed (GtkWidget *omenu, gpointer user_data)
 {
     GtkWidget *widget = GTK_WIDGET (user_data);
 
-    gint idx = gtk_option_menu_get_history (omenu);
+#if GTK_CHECK_VERSION(2, 24, 0)
+    gint idx = gtk_combo_box_get_active (GTK_COMBO_BOX (omenu));
+#else
+    gint idx = gtk_option_menu_get_history (GTK_OPTION_MENU (omenu));
+#endif
 
     for (int i = 0; preedit_style[i].data && i <= idx; i++) {
         if (i == idx &&
@@ -1879,14 +2180,18 @@ on_dict_menu_label_toggled (GtkToggleBut
 }
 
 static void
-on_key_category_menu_changed (GtkOptionMenu *omenu, gpointer user_data)
+on_key_category_menu_changed (GtkWidget *omenu, gpointer user_data)
 {
     GtkTreeView *treeview = GTK_TREE_VIEW (user_data);
     GtkListStore *store = GTK_LIST_STORE (gtk_tree_view_get_model (treeview));
 
     gtk_list_store_clear (store);
 
-    gint idx = gtk_option_menu_get_history (omenu);
+#if GTK_CHECK_VERSION(2, 24, 0)
+    gint idx = gtk_combo_box_get_active (GTK_COMBO_BOX (omenu));
+#else
+    gint idx = gtk_option_menu_get_history (GTK_OPTION_MENU (omenu));
+#endif
 
     bool use_filter = false;
 
@@ -1911,10 +2216,14 @@ on_key_category_menu_changed (GtkOptionM
 }
 
 static void
-on_key_theme_menu_changed (GtkOptionMenu *omenu, gpointer user_data)
+on_key_theme_menu_changed (GtkWidget *omenu, gpointer user_data)
 {
-    gint idx = gtk_option_menu_get_history (omenu);
-    GtkWidget *menu = gtk_option_menu_get_menu (omenu);
+#if GTK_CHECK_VERSION(2, 24, 0)
+    gint idx = gtk_combo_box_get_active (GTK_COMBO_BOX (omenu));
+    gint theme_idx = idx - 2; // user definad and default
+#else
+    gint idx = gtk_option_menu_get_history (GTK_OPTION_MENU (omenu));
+    GtkWidget *menu = gtk_option_menu_get_menu (GTK_OPTION_MENU (omenu));
     GList *list = gtk_container_get_children (GTK_CONTAINER (menu));
     GtkWidget *menuitem = GTK_WIDGET (g_list_nth_data (list, idx));
 
@@ -1923,6 +2232,7 @@ on_key_theme_menu_changed (GtkOptionMenu
 
     gint theme_idx = GPOINTER_TO_INT (g_object_get_data (G_OBJECT (menuitem),
                                                          INDEX_KEY));
+#endif
 
     // clear all key bindings
     if (idx != 0) {
@@ -1974,9 +2284,15 @@ on_key_theme_menu_changed (GtkOptionMenu
 
     // sync widgets
     if (idx != KEY_THEME_INDEX_USER_DEFINED) {
+#if GTK_CHECK_VERSION(2, 24, 0)
+        gtk_combo_box_set_active
+            (GTK_COMBO_BOX (__widget_key_categories_menu),
+             KEY_CATEGORY_INDEX_ALL);
+#else
         gtk_option_menu_set_history
             (GTK_OPTION_MENU (__widget_key_categories_menu),
              KEY_CATEGORY_INDEX_ALL);
+#endif
         gtk_widget_set_sensitive (__widget_key_filter, FALSE);
         gtk_widget_set_sensitive (__widget_key_filter_button, FALSE);
         GtkTreeModel *model;
@@ -2041,8 +2357,13 @@ on_key_list_view_key_press (GtkWidget *w
     GtkTreeView *treeview = GTK_TREE_VIEW (widget);
 
     switch (event->keyval) {
+#if GTK_CHECK_VERSION(3, 0, 0)
+    case GDK_KEY_Return:
+    case GDK_KEY_KP_Enter:
+#else
     case GDK_Return:
     case GDK_KP_Enter:
+#endif
         key_list_view_popup_key_selection (treeview);
         break;
     }
