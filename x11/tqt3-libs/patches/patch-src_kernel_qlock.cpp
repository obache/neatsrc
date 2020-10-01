$NetBSD$

--- src/kernel/qlock.cpp.orig	2019-02-16 18:13:44.000000000 +0000
+++ src/kernel/qlock.cpp
@@ -50,7 +50,7 @@
 #define _WANT_SEMUN
 #include <sys/sem.h>
 #if defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED) \
-    || defined(Q_OS_FREEBSD) || defined(Q_OS_OPENBSD) || defined(Q_OS_NETBSD) || defined(Q_OS_BSDI)
+    || defined(Q_OS_FREEBSD) || defined(Q_OS_OPENBSD) || defined(Q_OS_NETBSD) || defined(Q_OS_BSDI) || defined(Q_OS_INTERIX)
 /* union semun is defined by including <sys/sem.h> */
 #else
 /* according to X/OPEN we have to define it ourselves */
