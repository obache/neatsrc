$NetBSD$

* see upstream #2744

--- src/tools/qmutex_unix.cpp.orig	2018-08-25 07:26:27.000000000 +0000
+++ src/tools/qmutex_unix.cpp
@@ -47,6 +47,7 @@ typedef pthread_mutex_t     Q_MUTEX_T;
 // POSIX threads mutex types
 #if (defined(PTHREAD_MUTEX_RECURSIVE) && defined(PTHREAD_MUTEX_DEFAULT)) && \
     !defined(Q_OS_UNIXWARE) && !defined(Q_OS_SOLARIS) && \
+    !defined(Q_OS_NETBSD) && \
     !defined(Q_OS_MAC)
 // POSIX 1003.1c-1995 - We love this OS
 #  define Q_MUTEX_SET_TYPE(a, b) pthread_mutexattr_settype((a), (b))
