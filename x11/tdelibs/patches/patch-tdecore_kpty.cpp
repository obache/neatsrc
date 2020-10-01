$NetBSD$

--- tdecore/kpty.cpp.orig	2020-04-10 23:08:30.000000000 +0000
+++ tdecore/kpty.cpp
@@ -308,7 +308,7 @@ bool KPty::open()
   if (d->masterFd >= 0)
     return true;
 
-#if defined(__OpenBSD__) || defined(__FreeBSD__)
+#if defined(HAVE_OPENPTY)
   char cpty[16];
 
   if (openpty(&d->masterFd, &d->slaveFd, cpty, NULL, &d->winSize) == 0) {
