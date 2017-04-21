$NetBSD$

* Change to IANA registerd service name

--- lib/DtSvc/include/SPC/spc-proto.h.orig	2016-06-19 18:46:29.000000000 +0000
+++ lib/DtSvc/include/SPC/spc-proto.h
@@ -41,7 +41,7 @@
 
 /* The internet service */
 
-#define SPC_SERVICE	(XeString)"dtspc"  /* The name of the registered service */
+#define SPC_SERVICE	(XeString)"dtspcd"  /* The name of the registered service */
 #define SPC_PROTOCOL	(XeString)"tcp"	 /* The name of the registered protocol */
 
   /*  MUST be a DECIMAL number as "%d" */
