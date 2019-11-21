$NetBSD$

* it is used unconditionally

--- lib/csa/connection.h.orig	2019-11-16 02:06:11.000000000 +0000
+++ lib/csa/connection.h
@@ -72,7 +72,6 @@ typedef struct conn {
 	enum clnt_stat	stat;
 } _DtCm_Connection;
 
-#ifdef SunOS
 extern enum clnt_stat _DtCm_clnt_call P((
 				_DtCm_Connection *conn,
 				u_long proc,
@@ -81,7 +80,6 @@ extern enum clnt_stat _DtCm_clnt_call P(
 				xdrproc_t outproc,
 				caddr_t out,
 				struct timeval tout));
-#endif
 
 extern CSA_return_code _DtCm_add_registration P((
 				_DtCm_Client_Info *ci,
