$NetBSD$

--- libmate-panel-applet/mate-panel-applet.c.orig	2015-05-25 10:28:05.000000000 +0000
+++ libmate-panel-applet/mate-panel-applet.c
@@ -2006,6 +2006,7 @@ mate_panel_applet_init (MatePanelApplet 
 	applet->priv->size   = 24;
 
 	applet->priv->panel_action_group = gtk_action_group_new ("PanelActions");
+	_MATE_PANEL_APPLET_SETUP_GETTEXT(FALSE);
 	gtk_action_group_set_translation_domain (applet->priv->panel_action_group, GETTEXT_PACKAGE);
 	gtk_action_group_add_actions (applet->priv->panel_action_group,
 				      menu_entries,
