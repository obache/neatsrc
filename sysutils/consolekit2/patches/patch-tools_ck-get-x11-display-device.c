$NetBSD$

--- tools/ck-get-x11-display-device.c.orig	2015-06-21 15:38:32.000000000 +0000
+++ tools/ck-get-x11-display-device.c
@@ -138,7 +138,11 @@ get_tty_for_display (Display *xdisplay)
                 goto out;
         }
 
+#if defined(__NetBSD__)
+        display = g_strdup_printf ("/dev/ttyE%ld", vt-1);
+#else
         display = g_strdup_printf ("/dev/tty%ld", vt);
+#endif
 
 out:
         if (return_value != NULL) {
