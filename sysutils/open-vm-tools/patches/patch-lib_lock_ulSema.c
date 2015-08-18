$NetBSD$

--- lib/lock/ulSema.c.orig	2015-06-17 16:14:30.000000000 +0000
+++ lib/lock/ulSema.c
@@ -28,6 +28,12 @@
 #undef _XOPEN_SOURCE
 #define _XOPEN_SOURCE 600
 #endif
+#if defined(__NetBSD__)
+#if !defined(_NETBSD_SOURCE)
+#define _NETBSD_SOURCE
+#endif
+#include <sys/param.h>
+#endif
 #include <semaphore.h>
 #include <sys/time.h>
 #endif
@@ -306,6 +312,33 @@ MXUserDown(NativeSemaphore *sema)  // IN
    return err;
 }
 
+#if defined(__NetBSD__) && (__NetBSD_Version__ < 699000400)
+static inline int sem_timedwait(sem_t *sem, struct timespec *ts) {
+  struct timespec onems = { 0, 1000000 };
+  struct timespec total = { 0, 0 };
+  struct timespec unslept;
+  struct timespec elapsed;
+  struct timespec tmp;
+
+  while (timespeccmp(ts, &total, >)) {
+    if (sem_trywait(sem) == 0)
+      return 0;
+
+    if (errno != EAGAIN)
+      return -1;
+
+    (void)nanosleep(&onems, &unslept);
+
+    timespecsub(&onems, &unslept, &elapsed);
+    timespecadd(&total, &elapsed, &tmp);
+    total.tv_sec = tmp.tv_sec;
+    total.tv_nsec = tmp.tv_nsec;
+  }
+  errno = ETIMEDOUT;
+  return -1;
+}
+#endif /* __NetBSD__ */
+
 static int
 MXUserTimedDown(NativeSemaphore *sema,  // IN:
                 uint32 msecWait,        // IN:
