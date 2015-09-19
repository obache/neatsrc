$NetBSD$

* NetBSD support

--- src/polkit/polkitunixprocess.c.orig	2014-01-14 22:42:25.000000000 +0000
+++ src/polkit/polkitunixprocess.c
@@ -29,6 +29,10 @@
 #include <sys/sysctl.h>
 #include <sys/user.h>
 #endif
+#ifdef __NetBSD__
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#endif
 #include <stdlib.h>
 #include <string.h>
 #include <errno.h>
@@ -89,6 +93,9 @@ static gint _polkit_unix_process_get_own
 #ifdef HAVE_FREEBSD
 static gboolean get_kinfo_proc (gint pid, struct kinfo_proc *p);
 #endif
+#if defined(__NetBSD__)
+static gboolean get_kinfo_proc (gint pid, struct kinfo_proc2 *p);
+#endif
 
 G_DEFINE_TYPE_WITH_CODE (PolkitUnixProcess, polkit_unix_process, G_TYPE_OBJECT,
                          G_IMPLEMENT_INTERFACE (POLKIT_TYPE_SUBJECT, subject_iface_init)
@@ -554,12 +561,38 @@ get_kinfo_proc (pid_t pid, struct kinfo_
 }
 #endif
 
+#ifdef __NetBSD__
+static gboolean
+get_kinfo_proc (pid_t pid, struct kinfo_proc2 *p)
+{
+  int name[6];
+  u_int namelen;
+  size_t sz;
+
+  sz = sizeof(*p);
+  namelen = 0;
+  name[namelen++] = CTL_KERN;
+  name[namelen++] = KERN_PROC2;
+  name[namelen++] = KERN_PROC_PID;
+  name[namelen++] = pid;
+  name[namelen++] = sz;
+  name[namelen++] = 1;
+
+  if (sysctl (name, namelen, p, &sz, NULL, 0) == -1) {
+    perror("sysctl kern.proc2.pid");
+    return FALSE;
+  }
+
+  return TRUE;
+}
+#endif
+
 static guint64
 get_start_time_for_pid (pid_t    pid,
                         GError **error)
 {
   guint64 start_time;
-#ifndef HAVE_FREEBSD
+#if !defined(HAVE_FREEBSD) && !defined(__NetBSD__)
   gchar *filename;
   gchar *contents;
   size_t length;
@@ -632,7 +665,11 @@ get_start_time_for_pid (pid_t    pid,
   g_free (filename);
   g_free (contents);
 #else
+#if defined(__NetBSD__)
+  struct kinfo_proc2 p;
+#else
   struct kinfo_proc p;
+#endif
 
   start_time = 0;
 
@@ -647,7 +684,11 @@ get_start_time_for_pid (pid_t    pid,
       goto out;
     }
 
+#ifdef HAVE_FREEBSD
   start_time = (guint64) p.ki_start.tv_sec;
+#else
+  start_time = (guint64) p.p_ustart_sec;
+#endif
 
 out:
 #endif
@@ -664,6 +705,8 @@ _polkit_unix_process_get_owner (PolkitUn
   gchar **lines;
 #ifdef HAVE_FREEBSD
   struct kinfo_proc p;
+#elif defined(__NetBSD__)
+  struct kinfo_proc2 p;
 #else
   gchar filename[64];
   guint n;
@@ -676,7 +719,7 @@ _polkit_unix_process_get_owner (PolkitUn
   lines = NULL;
   contents = NULL;
 
-#ifdef HAVE_FREEBSD
+#if defined(HAVE_FREEBSD) || defined(__NetBSD__)
   if (get_kinfo_proc (process->pid, &p) == 0)
     {
       g_set_error (error,
@@ -688,8 +731,12 @@ _polkit_unix_process_get_owner (PolkitUn
       goto out;
     }
 
+#ifdef HAVE_FREEBSD
   result = p.ki_uid;
 #else
+  result = p.p_uid;
+#endif
+#else
 
   /* see 'man proc' for layout of the status file
    *
