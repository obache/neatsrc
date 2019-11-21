$NetBSD$

* format string is used as const

--- programs/dtmail/include/DtMail/DtMailServer.hh.orig	2019-11-16 02:06:11.000000000 +0000
+++ programs/dtmail/include/DtMail/DtMailServer.hh
@@ -201,8 +201,8 @@ protected:
     //
     // Generic Access Protocol methods
     //
-    DTMailError_t	do_send(char *fmt, ...);
-    DTMailError_t	do_transaction(char *fmt, ...);
+    DTMailError_t	do_send(const char *fmt, ...);
+    DTMailError_t	do_transaction(const char *fmt, ...);
     Boolean		is_inbox();
     DTMailError_t	ptrans_retrieve_readandappend(DtMailEnv&, long);
     void		send_info_message(DtMailCallbackOp);
