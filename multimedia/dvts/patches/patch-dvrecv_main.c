$NetBSD$

* missing prototype for set_sig_behavior

--- dvrecv/main.c.orig	2008-03-12 10:28:07.000000000 +0000
+++ dvrecv/main.c
@@ -62,6 +62,7 @@
 
 #include "ieee1394.h"
 #include "write.h"
+#include "sig-behavior.h"
 
 /* this structure contains all configuration */
 struct dvrecv_param dvrecv_param;
