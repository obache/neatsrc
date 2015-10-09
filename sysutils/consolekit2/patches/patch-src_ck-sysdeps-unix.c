$NetBSD$

* NetBSD support

--- src/ck-sysdeps-unix.c.orig	2015-08-09 07:46:18.000000000 +0000
+++ src/ck-sysdeps-unix.c
@@ -36,10 +36,14 @@
 #include <linux/kd.h>
 #endif
 
-#if defined(__OpenBSD__)
+#if defined(__NetBSD__) || defined(__OpenBSD__)
 #include <dev/wscons/wsdisplay_usl_io.h>
 #endif
 
+#if defined(__NetBSD__)
+#include <sys/un.h>
+#endif
+
 #ifdef HAVE_SYS_VT_H
 #include <sys/vt.h>
 #endif
@@ -108,6 +112,22 @@ ck_get_socket_peer_credentials   (int   
         if (ucred != NULL) {
                 ucred_free (ucred);
         }
+#elif defined(LOCAL_PEEREID)
+        struct unpcbid cr;
+        socklen_t      cr_len;
+
+        cr_len = sizeof (cr);
+
+        if (getsockopt (socket_fd, 0, LOCAL_PEEREID, &cr, &cr_len) == 0 && cr_len == sizeof (cr)) {
+                pid_read = cr.unp_pid;
+                uid_read = cr.unp_euid;
+                ret = TRUE;
+        } else {
+                g_warning ("Failed to getsockopt() credentials, returned len %d/%d: %s\n",
+                           cr_len,
+                           (int) sizeof (cr),
+                           g_strerror (errno));
+        }
 #elif defined(HAVE_GETPEEREID)
 	gid_t dummy;
 
@@ -203,7 +223,7 @@ out:
 gboolean
 ck_fd_is_a_console (int fd)
 {
-#if defined(__linux__) || defined(__OpenBSD__)
+#if defined(__linux__) || defined(__NetBSD__) || defined(__OpenBSD__)
         struct vt_stat vts;
 #elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined (__DragonFly__)
         int vers;
@@ -211,7 +231,7 @@ ck_fd_is_a_console (int fd)
         int  kb_ok;
 
         errno = 0;
-#if defined(__linux__) || defined(__OpenBSD__)
+#if defined(__linux__) || defined(__NetBSD__) || defined(__OpenBSD__)
         kb_ok = (ioctl (fd, VT_GETSTATE, &vts) == 0);
 #elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined (__DragonFly__)
         kb_ok = (ioctl (fd, CONS_GETVERS, &vers) == 0);
@@ -289,6 +309,13 @@ ck_get_a_console_fd (void)
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
