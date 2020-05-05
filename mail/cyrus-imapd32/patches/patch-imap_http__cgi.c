$NetBSD$

* exactly declare `environ';

--- imap/http_cgi.c.orig	2020-04-24 02:03:00.000000000 +0000
+++ imap/http_cgi.c
@@ -163,6 +163,7 @@ static int meth_get(struct transaction_t
     hdrcache_t resp_hdrs = NULL;
     struct body_t resp_body;
     long code = 0;
+    extern char **environ;
     
     memset(&resp_body, 0, sizeof(struct body_t));
 
