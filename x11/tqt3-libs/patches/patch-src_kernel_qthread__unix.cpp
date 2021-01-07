$NetBSD$

--- src/kernel/qthread_unix.cpp.orig	2020-10-16 13:12:04.000000000 +0000
+++ src/kernel/qthread_unix.cpp
@@ -51,6 +51,7 @@ typedef pthread_mutex_t Q_MUTEX_T;
 
 #include <errno.h>
 #include <sched.h>
+#include <unistd.h>
 
 #if defined(QT_USE_GLIBMAINLOOP)
 #include <glib.h>
