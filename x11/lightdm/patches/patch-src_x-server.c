$NetBSD$

* for NetBSD VT name

--- src/x-server.c.orig	2015-10-16 10:05:05.000000000 +0000
+++ src/x-server.c
@@ -155,7 +155,11 @@ x_server_connect_session (DisplayServer 
     {
         gchar *t;
 
+#if defined(__NetBSD__)
+        t = g_strdup_printf ("/dev/ttyE%d", vt - 1);
+#else
         t = g_strdup_printf ("/dev/tty%d", vt);
+#endif
         session_set_tty (session, t);
         g_free (t);
 
