$NetBSD$

--- imap/httpd.c.orig	2015-05-08 03:49:52.000000000 +0000
+++ imap/httpd.c
@@ -3509,7 +3509,7 @@ static int meth_get(struct transaction_t
     static struct buf pathbuf = BUF_INITIALIZER;
     struct stat sbuf;
     const char *msg_base = NULL;
-    unsigned long msg_size = 0;
+    size_t msg_size = 0;
     struct resp_body_t *resp_body = &txn->resp_body;
 
     /* Check if this is a request for /.well-known/ listing */
