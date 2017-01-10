$NetBSD$

* rewrite deprecated functions for GTK+3

--- src/scim_array_imengine_setup.cpp.orig	2008-05-03 12:47:46.000000000 +0000
+++ src/scim_array_imengine_setup.cpp
@@ -150,39 +150,66 @@ on_default_key_selection_clicked     (Gt
                                       gpointer         user_data);
 
 static GtkWidget *
+#if GTK_CHECK_VERSION(2, 12, 0)
+create_options_page();
+#else
 create_options_page(GtkTooltips *tooltip);
+#endif
 
 
 // Function implementations.
 static GtkWidget *
+#if GTK_CHECK_VERSION(2, 12, 0)
+create_options_page()
+#else
 create_options_page(GtkTooltips *tooltips)
+#endif
 {
     GtkWidget *vbox;
     GtkWidget *button;
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+    vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 12);
+#else
     vbox = gtk_vbox_new (FALSE, 12);
+#endif
     gtk_container_set_border_width(GTK_CONTAINER(vbox), 12);
 
     button = gtk_check_button_new_with_mnemonic (_("Show Special Code"));
     gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);
+#if GTK_CHECK_VERSION(2, 12, 0)
+    gtk_widget_set_tooltip_text(button,
+                          _("To notify if the character has the special code"));
+#else
     gtk_tooltips_set_tip(tooltips, button,
                           _("To notify if the character has the special code"), NULL);
+#endif
     g_signal_connect(G_OBJECT(button), "toggled",
                      G_CALLBACK(on_default_toggle_button_toggled), NULL);
     show_special_code_button = button;
 
     button = gtk_check_button_new_with_mnemonic(_("Only Special Code Input Mode"));
     gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);
+#if GTK_CHECK_VERSION(2, 12, 0)
+    gtk_widget_set_tooltip_text(button,
+                            _("If the character has the special code, you will be confined to use it"));
+#else
     gtk_tooltips_set_tip(tooltips, button,
                             _("If the character has the special code, you will be confined to use it"), NULL);
+#endif
     g_signal_connect(G_OBJECT(button), "toggled",
                      G_CALLBACK(on_default_toggle_button_toggled), NULL);
     special_code_only_button = button;
 
     button = gtk_check_button_new_with_mnemonic(_("Use Phrase Library"));
     gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);
+#if GTK_CHECK_VERSION(2, 12, 0)
+    gtk_widget_set_tooltip_text(button,
+            _("Turn on phrase input mode. (Enable after restart)"));
+#else
     gtk_tooltips_set_tip(tooltips, button,
             _("Turn on phrase input mode. (Enable after restart)"), NULL);
+#endif
     g_signal_connect(G_OBJECT(button), "toggled",
                      G_CALLBACK(on_default_toggle_button_toggled), NULL);
     phrases_library_button = button;
@@ -197,10 +224,14 @@ create_options_page(GtkTooltips *tooltip
             (GtkAttachOptions) (GTK_FILL),
             (GtkAttachOptions) (GTK_FILL), 4, 4); 
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+    GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 12);
+#else
     GtkWidget *hbox = gtk_hbox_new(FALSE, 12);
+#endif
 
     GtkWidget *entry = gtk_entry_new();
-    gtk_entry_set_editable (GTK_ENTRY (entry), FALSE);
+    gtk_editable_set_editable (GTK_EDITABLE (entry), FALSE);
     gtk_entry_set_text (GTK_ENTRY (entry), "");
     gtk_box_pack_start(GTK_BOX(hbox), entry, FALSE, TRUE, 0);
     g_signal_connect(G_OBJECT(entry), "changed",
@@ -221,10 +252,14 @@ create_options_page(GtkTooltips *tooltip
             (GtkAttachOptions) (GTK_FILL),
             (GtkAttachOptions) (GTK_FILL), 4, 4); 
 
+#if GTK_CHECK_VERSION(3, 0, 0)
+    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 12);
+#else
     hbox = gtk_hbox_new(FALSE, 12);
+#endif
 
     entry = gtk_entry_new();
-    gtk_entry_set_editable (GTK_ENTRY (entry), FALSE);
+    gtk_editable_set_editable (GTK_EDITABLE (entry), FALSE);
     gtk_entry_set_text (GTK_ENTRY (entry), "");
     gtk_box_pack_start(GTK_BOX(hbox), entry, FALSE, TRUE, 0);
     g_signal_connect(G_OBJECT(entry), "changed",
@@ -248,15 +283,21 @@ create_setup_window ()
     GtkWidget *notebook;
     GtkWidget *label;
     GtkWidget *page;
+#if !GTK_CHECK_VERSION(2, 12, 0)
     GtkTooltips *tooltips;
 
     tooltips = gtk_tooltips_new ();
+#endif
 
     // Create the Notebook.
     notebook = gtk_notebook_new ();
 
     // Create the first page.
+#if GTK_CHECK_VERSION(2, 12, 0)
+    page = create_options_page();
+#else
     page = create_options_page(tooltips);
+#endif
     label = gtk_label_new (_("Options"));
     gtk_notebook_append_page (GTK_NOTEBOOK (notebook), page, label);
 
