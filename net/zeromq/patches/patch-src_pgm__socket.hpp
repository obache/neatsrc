$NetBSD$

* NetBSD too

--- src/pgm_socket.hpp.orig	2014-10-14 14:07:10.000000000 +0000
+++ src/pgm_socket.hpp
@@ -31,7 +31,7 @@
 
 #include <pgm/pgm.h>
 
-#ifdef ZMQ_HAVE_OSX
+#if defined(ZMQ_HAVE_OSX) || defined(ZMQ_HAVE_NETBSD)
 #include <pgm/in.h>
 #endif
 
