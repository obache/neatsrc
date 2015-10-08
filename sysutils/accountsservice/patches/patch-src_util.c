$NetBSD$

* "loginuid" is only for Linux

--- src/util.c.orig	2014-11-04 03:46:00.000000000 +0000
+++ src/util.c
@@ -175,15 +175,18 @@ sys_log (GDBusMethodInvocation *context,
 static void
 get_caller_loginuid (GDBusMethodInvocation *context, gchar *loginuid, gint size)
 {
-        GPid pid;
         gint uid;
+#if defined(linux)
+        GPid pid;
         gchar *path;
         gchar *buf;
+#endif
 
         if (!get_caller_uid (context, &uid)) {
                 uid = getuid ();
         }
 
+#if defined(linux)
         if (get_caller_pid (context, &pid)) {
                 path = g_strdup_printf ("/proc/%d/loginuid", (int) pid);
         } else {
@@ -199,6 +202,9 @@ get_caller_loginuid (GDBusMethodInvocati
         }
 
         g_free (path);
+#else
+        g_snprintf (loginuid, size, "%d", uid);
+#endif
 }
 
 static gboolean
@@ -230,12 +236,14 @@ compat_check_exit_status (int      estat
 static void
 setup_loginuid (gpointer data)
 {
+#if defined(linux)
         const char *id = data;
         int fd;
 
         fd = open ("/proc/self/loginuid", O_WRONLY);
         write (fd, id, strlen (id));
         close (fd);
+#endif
 }
 
 gboolean
