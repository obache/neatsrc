$NetBSD$

* missing prototype for set_sig_behavior

--- dvsend/main.c.orig	2008-03-12 10:28:07.000000000 +0000
+++ dvsend/main.c
@@ -60,6 +60,7 @@
 #include "udp.h"
 #include "multicast.h"
 #include "rtp.h"
+#include "sig-behavior.h"
 
 #include "ieee1394.h"
 
