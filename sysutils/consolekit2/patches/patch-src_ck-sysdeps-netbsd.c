$NetBSD$

* Add login session id detection support for NetBSD

--- src/ck-sysdeps-netbsd.c.orig	2015-10-21 16:12:21.000000000 +0000
+++ src/ck-sysdeps-netbsd.c
@@ -315,9 +315,21 @@ gboolean
 ck_unix_pid_get_login_session_id (pid_t  pid,
                                   char **idp)
 {
+        pid_t sid;
+
         g_return_val_if_fail (pid > 1, FALSE);
 
-        return FALSE;
+        sid = getsid(pid);
+
+        if (sid < 0) {
+                return FALSE;
+        }
+
+        if (idp != NULL) {
+                *idp = g_strdup_printf ("%lu", (unsigned long int)sid);
+        }
+
+        return TRUE;
 }
 
 gboolean
