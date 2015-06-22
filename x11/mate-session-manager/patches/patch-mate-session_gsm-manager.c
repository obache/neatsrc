$NetBSD$

--- mate-session/gsm-manager.c.orig	2015-06-11 19:13:45.000000000 +0000
+++ mate-session/gsm-manager.c
@@ -3385,8 +3385,8 @@ gsm_manager_can_shutdown (GsmManager *ma
 #ifdef HAVE_SYSTEMD
         GsmSystemd *systemd;
 #endif
-        gboolean can_suspend;
-        gboolean can_hibernate;
+        gboolean can_suspend = FALSE;
+        gboolean can_hibernate = FALSE;
 #ifdef HAVE_UPOWER
         g_object_get (manager->priv->up_client,
                       "can-suspend", &can_suspend,
