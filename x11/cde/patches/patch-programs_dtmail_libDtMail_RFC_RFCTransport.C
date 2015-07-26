$NetBSD$

--- programs/dtmail/libDtMail/RFC/RFCTransport.C.orig	2015-05-09 23:09:11.000000000 +0000
+++ programs/dtmail/libDtMail/RFC/RFCTransport.C
@@ -740,7 +740,7 @@ RFCTransport::launchSendmail(DtMailEnv &
     if (error.isSet()) {
 #if defined(USL) || defined(__uxp__)
         mailer = "/usr/ucblib/sendmail";
-#elif defined(__OpenBSD__)
+#elif defined(__OpenBSD__) || defined(__NetBSD__)
 	mailer = "/usr/sbin/sendmail";
 #else
         mailer = "/usr/lib/sendmail";
