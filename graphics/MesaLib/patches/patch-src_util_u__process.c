$NetBSD$

* Fix NetBSD detection

--- src/util/u_process.c.orig	2019-09-03 10:54:50.000000000 +0000
+++ src/util/u_process.c
@@ -87,8 +87,11 @@ __getProgramName()
 #    if (__FreeBSD_version >= 440000)
 #        define GET_PROGRAM_NAME() getprogname()
 #    endif
-#elif defined(__NetBSD__) && defined(__NetBSD_Version__) && (__NetBSD_Version__ >= 106000100)
-#    define GET_PROGRAM_NAME() getprogname()
+#elif defined(__NetBSD__)
+#    include <sys/param.h>
+#    if defined(__NetBSD_Version__) && (__NetBSD_Version__ >= 106000100)
+#        define GET_PROGRAM_NAME() getprogname()
+#    endif
 #elif defined(__DragonFly__)
 #    define GET_PROGRAM_NAME() getprogname()
 #elif defined(__APPLE__)
@@ -123,7 +126,7 @@ __getProgramName()
 #endif
 
 #if !defined(GET_PROGRAM_NAME)
-#    if defined(__OpenBSD__) || defined(NetBSD) || defined(__UCLIBC__) || defined(ANDROID)
+#    if defined(__OpenBSD__) || defined(__NetBSD__) || defined(__UCLIBC__) || defined(ANDROID)
 /* This is a hack. It's said to work on OpenBSD, NetBSD and GNU.
  * Rogelio M.Serrano Jr. reported it's also working with UCLIBC. It's
  * used as a last resort, if there is no documented facility available. */
