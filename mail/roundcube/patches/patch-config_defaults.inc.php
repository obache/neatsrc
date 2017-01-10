$NetBSD$

* move writable directories with default config

--- config/defaults.inc.php.orig	2016-04-17 16:37:51.000000000 +0000
+++ config/defaults.inc.php
@@ -327,11 +327,11 @@ $config['user_aliases'] = false;
 // use this folder to store log files
 // must be writeable for the user who runs PHP process (Apache user if mod_php is being used)
 // This is used by the 'file' log driver.
-$config['log_dir'] = RCUBE_INSTALL_PATH . 'logs/';
+$config['log_dir'] = '@VARBASE@/log/roundcube/';
 
 // use this folder to store temp files
 // must be writeable for the user who runs PHP process (Apache user if mod_php is being used)
-$config['temp_dir'] = RCUBE_INSTALL_PATH . 'temp/';
+$config['temp_dir'] = '@VARBASE@/tmp/roundcube/';
 
 // expire files in temp_dir after 48 hours
 // possible units: s, m, h, d, w
