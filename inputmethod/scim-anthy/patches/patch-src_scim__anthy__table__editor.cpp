$NetBSD$

* add gtk3+ support

--- src/scim_anthy_table_editor.cpp.orig	2008-04-24 03:49:53.000000000 +0000
+++ src/scim_anthy_table_editor.cpp
@@ -132,10 +132,20 @@ scim_anthy_table_editor_init (ScimAnthyT
                              GTK_WIN_POS_CENTER_ON_PARENT);
 
     // edit area
+#if GTK_CHECK_VERSION(3, 0, 0)
+    GtkWidget *hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
+#else
     GtkWidget *hbox = gtk_hbox_new (FALSE, 0);
+#endif
     gtk_container_set_border_width (GTK_CONTAINER (hbox), 5);
+#if GTK_CHECK_VERSION(3, 0, 0)
+    gtk_box_pack_start
+		(GTK_BOX (gtk_dialog_get_content_area (GTK_DIALOG (editor))),
+		 hbox, TRUE, TRUE, 0);
+#else
     gtk_box_pack_start (GTK_BOX (GTK_DIALOG (editor)->vbox), hbox,
                         TRUE, TRUE, 0);
+#endif
     gtk_widget_show (hbox);
 
     // tree view area
@@ -162,7 +172,11 @@ scim_anthy_table_editor_init (ScimAnthyT
     gtk_tree_view_set_headers_clickable (GTK_TREE_VIEW (treeview), TRUE);
 
     // button area
+#if GTK_CHECK_VERSION(3, 0, 0)
+    GtkWidget *vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
+#else
     GtkWidget *vbox = gtk_vbox_new (FALSE, 0);
+#endif
     editor->button_area = vbox;
     gtk_box_pack_start (GTK_BOX (hbox), vbox, FALSE, FALSE, 5);
     gtk_widget_show (vbox);
