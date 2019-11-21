$NetBSD$

* fix const String usage

--- programs/dtmail/libDtMail/Common/DtMailServer.C.orig	2019-11-16 02:06:11.000000000 +0000
+++ programs/dtmail/libDtMail/Common/DtMailServer.C
@@ -167,8 +167,8 @@ DtMailServer::ptrans_retrieve_readandapp
 				DtMailEnv	&error,
 				long		len)
 {
-    static char	*pname = "DtMailServer::ptrans_retrieve_readandappend";
-    static char *from = "From ";
+    static const char	*pname = "DtMailServer::ptrans_retrieve_readandappend";
+    static const char *from = "From ";
     struct sigaction action, o_action;
     int from_done = FALSE;
     int done = FALSE;
@@ -283,7 +283,7 @@ DtMailServer::ptrans_retrieve_readandapp
 //
 
 DTMailError_t
-DtMailServer::do_send(char *fmt, ... )
+DtMailServer::do_send(const char *fmt, ... )
 {
     static char	*pname = "DtMailServer::do_send";
     char	*buf = new char[DTMAS_POPBUFSIZE+1];
@@ -337,9 +337,9 @@ DtMailServer::do_send(char *fmt, ... )
 #define DTMAS_COMMAND_TERMINATOR	"\r\n"
 #endif
 DTMailError_t
-DtMailServer::do_transaction(char *fmt, ... )
+DtMailServer::do_transaction(const char *fmt, ... )
 {
-    static char		*pname = "DtMailServer::do_transaction";
+    static const char	*pname = "DtMailServer::do_transaction";
     DTMailError_t	ok;
     char		*buf = new char[DTMAS_POPBUFSIZE+1];
     int			nbytes;
