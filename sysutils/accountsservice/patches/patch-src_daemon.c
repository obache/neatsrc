$NetBSD$

* Monitor master password file as shadow on NetBSD
* -f option for userdel(8) is only in Linux

--- src/daemon.c.orig	2014-11-04 03:46:00.000000000 +0000
+++ src/daemon.c
@@ -46,7 +46,11 @@
 #include "util.h"
 
 #define PATH_PASSWD "/etc/passwd"
+#if defined(__NetBSD__)
+#define PATH_SHADOW "/etc/master.passwd"
+#else
 #define PATH_SHADOW "/etc/shadow"
+#endif
 #define PATH_GROUP "/etc/group"
 #define PATH_GDM_CUSTOM "/etc/gdm/custom.conf"
 
@@ -1078,6 +1082,7 @@ daemon_delete_user_authorized_cb (Daemon
         gchar *filename;
         struct passwd *pwent;
         const gchar *argv[6];
+        gint argc = 0;
 
         pwent = getpwuid (ud->uid);
 
@@ -1110,20 +1115,16 @@ daemon_delete_user_authorized_cb (Daemon
         g_remove (filename);
         g_free (filename);
 
-        argv[0] = "/usr/sbin/userdel";
+        argv[argc++] = "/usr/sbin/userdel";
+#if defined(linux)
+        argv[argc++] = "-f";
+#endif
         if (ud->remove_files) {
-                argv[1] = "-f";
-                argv[2] = "-r";
-                argv[3] = "--";
-                argv[4] = pwent->pw_name;
-                argv[5] = NULL;
-        }
-        else {
-                argv[1] = "-f";
-                argv[2] = "--";
-                argv[3] = pwent->pw_name;
-                argv[4] = NULL;
+                argv[argc++] = "-r";
         }
+        argv[argc++] = "--";
+        argv[argc++] = pwent->pw_name;
+        argv[argc++] = NULL;
 
         error = NULL;
         if (!spawn_with_login_uid (context, argv, &error)) {
