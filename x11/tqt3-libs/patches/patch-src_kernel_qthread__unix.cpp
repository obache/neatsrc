$NetBSD$

--- src/kernel/qthread_unix.cpp.orig	2020-04-10 10:04:43.000000000 +0000
+++ src/kernel/qthread_unix.cpp
@@ -51,6 +51,7 @@ typedef pthread_mutex_t Q_MUTEX_T;
 
 #include <errno.h>
 #include <sched.h>
+#include <unistd.h>
 
 #if defined(QT_USE_GLIBMAINLOOP)
 #include <glib.h>
@@ -331,7 +332,10 @@ void TQThread::start(Priority priority)
     pthread_attr_init(&attr);
     pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
 
-#if !defined(Q_OS_OPENBSD) && defined(_POSIX_THREAD_PRIORITY_SCHEDULING) && (_POSIX_THREAD_PRIORITY_SCHEDULING-0 >= 0)
+#if defined(_POSIX_THREAD_PRIORITY_SCHEDULING) && (_POSIX_THREAD_PRIORITY_SCHEDULING-0 >= 0)
+#if _POSIX_THREAD_PRIORITY_SCHEDULING == 0 && defined _SC_THREAD_PRIORITY_SCHEDULING
+    if (sysconf(_SC_THREAD_PRIORITY_SCHEDULING) > 0) 
+#endif
     switch (priority) {
     case InheritPriority:
 	{
