$NetBSD$

* kill unportable ESTRPIPE

--- kttsd/players/alsaplayer/alsaplayer.cpp.orig	2019-01-20 02:54:14.000000000 +0000
+++ kttsd/players/alsaplayer/alsaplayer.cpp
@@ -1133,8 +1133,10 @@ ssize_t AlsaPlayer::pcm_write(char *data
             snd_pcm_wait(handle, 100);
         } else if (-EPIPE == r) {
             xrun();
+#ifdef ESTRPIPE
         } else if (-ESTRPIPE == r) {
             suspend();
+#endif
         } else if (-EBUSY == r){
             MSG("WARNING: sleeping while PCM BUSY");
             usleep(1000);
