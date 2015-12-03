$NetBSD$

* reduce default VT number (for NetBSD)

--- src/lightdm.c.orig	2015-11-18 23:15:37.000000000 +0000
+++ src/lightdm.c
@@ -1375,7 +1375,7 @@ main (int argc, char **argv)
     if (!config_has_key (config_get_instance (), "LightDM", "start-default-seat"))
         config_set_boolean (config_get_instance (), "LightDM", "start-default-seat", TRUE);
     if (!config_has_key (config_get_instance (), "LightDM", "minimum-vt"))
-        config_set_integer (config_get_instance (), "LightDM", "minimum-vt", 7);
+        config_set_integer (config_get_instance (), "LightDM", "minimum-vt", 5);
     if (!config_has_key (config_get_instance (), "LightDM", "guest-account-script"))
         config_set_string (config_get_instance (), "LightDM", "guest-account-script", "guest-account");
     if (!config_has_key (config_get_instance (), "LightDM", "greeter-user"))
