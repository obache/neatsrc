$NetBSD$

* emulate ESTRPIPE with EPIPE

--- flow/audioioalsa9.cc.orig	2011-11-29 07:37:07.000000000 +0000
+++ flow/audioioalsa9.cc
@@ -59,6 +59,10 @@
 #include "dispatcher.h"
 #include "iomanager.h"
 
+#if defined(HAVE_SND_PCM_RESUME) && !defined(ESTRPIPE)
+#define ESTRPIPE EPIPE
+#endif
+
 namespace Arts {
 
 class AudioIOALSA : public AudioIO, public IONotify  {
