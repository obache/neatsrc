$NetBSD$

* use SunOS API on NetBSD

--- mpeglib/lib/util/audio/audioIO.cpp.orig	2020-04-10 23:08:30.000000000 +0000
+++ mpeglib/lib/util/audio/audioIO.cpp
@@ -28,6 +28,8 @@
 #ifdef OS_BSD
 #ifdef __OpenBSD__
   #include "audioIO_sndio.cpp"
+#elif defined(__NetBSD__)
+  #include "audioIO_SunOS.cpp"
 #else
   #include "audioIO_Linux.cpp"
 #endif
