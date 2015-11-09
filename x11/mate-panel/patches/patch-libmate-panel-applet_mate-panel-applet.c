$NetBSD$

* Fix missing gettext setup for panel applet common parts
  https://github.com/mate-desktop/mate-panel/pull/339

--- libmate-panel-applet/mate-panel-applet.c.orig	2015-10-09 23:34:33.000000000 +0000
+++ libmate-panel-applet/mate-panel-applet.c
@@ -2019,6 +2019,7 @@ mate_panel_applet_init (MatePanelApplet 
 	applet->priv->size   = 24;
 
 	applet->priv->panel_action_group = gtk_action_group_new ("PanelActions");
+	_MATE_PANEL_APPLET_SETUP_GETTEXT(FALSE);
 	gtk_action_group_set_translation_domain (applet->priv->panel_action_group, GETTEXT_PACKAGE);
 	gtk_action_group_add_actions (applet->priv->panel_action_group,
 				      menu_entries,
