$NetBSD$

* NetBSD too

--- programs/dtmail/libDtMail/RFC/RFCTransport.C.orig	2018-07-06 18:05:20.000000000 +0000
+++ programs/dtmail/libDtMail/RFC/RFCTransport.C
@@ -741,7 +741,7 @@ RFCTransport::launchSendmail(DtMailEnv &
     const char * mailer;
     _session->mailRc(error)->getValue(error, "sendmail", &mailer);
     if (error.isSet()) {
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 	mailer = "/usr/sbin/sendmail";
 #else
         mailer = "/usr/lib/sendmail";
