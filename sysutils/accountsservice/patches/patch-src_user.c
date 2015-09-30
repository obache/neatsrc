$NetBSD$

* Add support for NetBSD

--- src/user.c.orig	2014-11-04 03:46:00.000000000 +0000
+++ src/user.c
@@ -159,6 +159,8 @@ user_update_from_pwent (User          *u
 {
 #ifdef HAVE_SHADOW_H
         struct spwd *spent;
+#else
+        struct passwd *spwent;
 #endif
         gchar *real_name;
         gboolean changed;
@@ -262,9 +264,17 @@ user_update_from_pwent (User          *u
         spent = getspnam (pwent->pw_name);
         if (spent)
                 passwd = spent->sp_pwdp;
+#else
+        spwent = getpwuid (pwent->pw_uid);
+        if (spwent)
+                passwd = spwent->pw_passwd;
 #endif
 
+#if defined(__NetBSD__)
+        if (passwd && strstr(passwd,"*LOCKED*") == passwd) {
+#else
         if (passwd && passwd[0] == '!') {
+#endif
                 locked = TRUE;
         }
         else {
@@ -1546,17 +1556,23 @@ user_change_locked_authorized_cb (Daemon
 {
         gboolean locked = GPOINTER_TO_INT (data);
         GError *error;
-        const gchar *argv[5];
+        const gchar *argv[6];
+        gint argc = 0;
 
         if (user->locked != locked) {
                 sys_log (context,
                          "%s account of user '%s' (%d)",
                          locked ? "locking" : "unlocking", user->user_name, user->uid);
-                argv[0] = "/usr/sbin/usermod";
-                argv[1] = locked ? "-L" : "-U";
-                argv[2] = "--";
-                argv[3] = user->user_name;
-                argv[4] = NULL;
+                argv[argc++] = "/usr/sbin/usermod";
+#if defined(__NetBSD__)
+                argv[argc++] = "-C";
+                argv[argc++] = locked ? "yes" : "no";
+#else
+                argv[argc++] = locked ? "-L" : "-U";
+#endif
+                argv[argc++] = "--";
+                argv[argc++] = user->user_name;
+                argv[argc++] = NULL;
 
                 error = NULL;
                 if (!spawn_with_login_uid (context, argv, &error)) {
@@ -1735,26 +1751,65 @@ user_change_password_mode_authorized_cb 
                 if (mode == PASSWORD_MODE_SET_AT_LOGIN ||
                     mode == PASSWORD_MODE_NONE) {
 
+#if defined(__NetBSD__)
+                        gchar* user_entry;
+                        struct passwd *pwent;
+                        pwent = getpwuid (user->uid);
+                        if (pwent == NULL) {
+                                throw_error (context, ERROR_FAILED, "cannot find uid '%d': %s", user->uid);
+                                return;
+                        }
+                        user_entry = g_strdup_printf ("%s::%d:%d:%s:%" G_GINT64_FORMAT ":%" G_GINT64_FORMAT ":%s:%s:%s",
+                                                      pwent->pw_name,
+                                                      pwent->pw_uid,
+                                                      pwent->pw_gid,
+                                                      pwent->pw_class,
+                                                      (gint64)pwent->pw_change,
+                                                      (gint64)pwent->pw_expire,
+                                                      pwent->pw_gecos,
+                                                      pwent->pw_dir,
+                                                      pwent->pw_shell);
+                        argv[0] = "/usr/bin/chpass";
+                        argv[1] = "-a";
+                        argv[2] = user_entry;
+                        argv[3] = "--";
+                        argv[4] = user->user_name;
+                        argv[5] = NULL;
+#else
                         argv[0] = "/usr/bin/passwd";
                         argv[1] = "-d";
                         argv[2] = "--";
                         argv[3] = user->user_name;
                         argv[4] = NULL;
+#endif
 
                         error = NULL;
                         if (!spawn_with_login_uid (context, argv, &error)) {
                                 throw_error (context, ERROR_FAILED, "running '%s' failed: %s", argv[0], error->message);
                                 g_error_free (error);
+#if defined(__NetBSD__)
+                                g_free (user_entry);
+#endif
                                 return;
                         }
+#if defined(__NetBSD__)
+                        g_free (user_entry);
+#endif
 
                         if (mode == PASSWORD_MODE_SET_AT_LOGIN) {
+#if defined(__NetBSD__)
+                                argv[0] = "/usr/sbin/usermod";
+                                argv[1] = "-F";
+                                argv[2] = user->user_name;
+                                argv[3] = NULL;
+#else
                                 argv[0] = "/usr/bin/chage";
                                 argv[1] = "-d";
                                 argv[2] = "0";
                                 argv[3] = "--";
                                 argv[4] = user->user_name;
                                 argv[5] = NULL;
+#endif
 
                                 error = NULL;
                                 if (!spawn_with_login_uid (context, argv, &error)) {
@@ -1778,11 +1833,20 @@ user_change_password_mode_authorized_cb 
                         }
                 }
                 else if (user->locked) {
+#if defined(__NetBSD__)
+                        argv[0] = "/usr/sbin/usermod";
+                        argv[1] = "-C";
+                        argv[2] = "off";
+                        argv[3] = "--";
+                        argv[4] = user->user_name;
+                        argv[5] = NULL;
+#else
                         argv[0] = "/usr/sbin/usermod";
                         argv[1] = "-U";
                         argv[2] = "--";
                         argv[3] = user->user_name;
                         argv[4] = NULL;
+#endif
 
                         error = NULL;
                         if (!spawn_with_login_uid (context, argv, &error)) {
