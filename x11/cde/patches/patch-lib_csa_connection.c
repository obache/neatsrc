$NetBSD$

* exactly declare as int

--- lib/csa/connection.c.orig	2019-11-16 02:06:11.000000000 +0000
+++ lib/csa/connection.c
@@ -62,8 +62,8 @@
 static struct timeval timeout_tv;
 static struct timeval retry_tv;
 static AUTH *unix_credential = NULL;
-static tcp_count = 0;
-static cl_count = 0;
+static int tcp_count = 0;
+static int cl_count = 0;
 static _DtCm_Client_Info *client_cache_head = NULL;
 static _DtCm_Client_Info *client_cache_tail = NULL;
 
