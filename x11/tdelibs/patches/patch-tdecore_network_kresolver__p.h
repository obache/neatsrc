$NetBSD$

--- tdecore/network/kresolver_p.h.orig	2020-04-10 23:08:30.000000000 +0000
+++ tdecore/network/kresolver_p.h
@@ -48,7 +48,6 @@ extern TQMutex getXXbyYYmutex;
 #endif
 
 /* some systems have the functions, but don't declare them */
-#ifndef __OpenBSD__
 #if defined(HAVE_GETSERVBYNAME_R) && !HAVE_DECL_GETSERVBYNAME_R
 extern "C" {
   struct servent;
@@ -70,7 +69,6 @@ extern "C" {
 				struct protoent** result);
 }
 #endif
-#endif
 
 /* decide whether res_init is thread-safe or not */
 #if defined(__GLIBC__)
