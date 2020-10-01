$NetBSD$

* Port to NetBSD

--- mpeglib/lib/util/audio/audioIO_SunOS.cpp.orig	2020-04-10 23:08:30.000000000 +0000
+++ mpeglib/lib/util/audio/audioIO_SunOS.cpp
@@ -8,13 +8,19 @@
  */
 
 #include <sys/types.h>
+#ifdef OS_SunOS
 #include <sys/stropts.h>
+#else
+#include <sys/ioctl.h>
+#endif
 #include <fcntl.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <sys/audioio.h>
+#ifdef OS_BSD
+#define uchar_t u_char
+#endif
 #include "audioIO.h"
-#include <iostream.h>
 
 /* declare these static to effectively isolate the audio device */
 
