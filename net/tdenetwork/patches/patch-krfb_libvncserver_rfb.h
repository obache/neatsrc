$NetBSD$

* Solaris amd64 support

--- krfb/libvncserver/rfb.h.orig	2016-11-07 05:16:16.000000000 +0000
+++ krfb/libvncserver/rfb.h
@@ -76,7 +76,7 @@ typedef unsigned long KeySym;
 #if defined(__sparc)
   /* SPARC here (big endian) */
 #define _BYTE_ORDER 4321
-#elif defined(__i386)
+#elif defined(__i386) || defined(__amd64)
 #define _BYTE_ORDER 1234
 #else
 #error Solaris 2.5.1 had ppc support did it not? :-)
