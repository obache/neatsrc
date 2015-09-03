$NetBSD$

* NetBSD support

--- src/ck-sysdeps-unix.c.orig	2015-08-09 07:46:18.000000000 +0000
+++ src/ck-sysdeps-unix.c
@@ -36,7 +36,7 @@
 #include <linux/kd.h>
 #endif
 
-#if defined(__OpenBSD__)
+#if defined(__NetBSD__) || defined(__OpenBSD__)
 #include <dev/wscons/wsdisplay_usl_io.h>
 #endif
 
@@ -203,7 +203,7 @@ out:
 gboolean
 ck_fd_is_a_console (int fd)
 {
-#if defined(__linux__) || defined(__OpenBSD__)
+#if defined(__linux__) || defined(__NetBSD__) || defined(__OpenBSD__)
         struct vt_stat vts;
 #elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined (__DragonFly__)
         int vers;
@@ -211,7 +211,7 @@ ck_fd_is_a_console (int fd)
         int  kb_ok;
 
         errno = 0;
-#if defined(__linux__) || defined(__OpenBSD__)
+#if defined(__linux__) || defined(__NetBSD__) || defined(__OpenBSD__)
         kb_ok = (ioctl (fd, VT_GETSTATE, &vts) == 0);
 #elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined (__DragonFly__)
         kb_ok = (ioctl (fd, CONS_GETVERS, &vers) == 0);
@@ -289,6 +289,13 @@ ck_get_a_console_fd (void)
         }
 #endif
 
+#if defined(__NetBSD__)
+        fd = open_a_console ("/dev/ttyE0");
+        if (fd >= 0) {
+                goto done;
+        }
+#endif
+
 #if defined(__OpenBSD__)
         fd = open_a_console ("/dev/ttyC0");
         if (fd >= 0) {
