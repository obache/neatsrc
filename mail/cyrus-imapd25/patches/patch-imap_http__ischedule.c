$NetBSD$

--- imap/http_ischedule.c.orig	2015-05-08 03:49:52.000000000 +0000
+++ imap/http_ischedule.c
@@ -974,7 +974,7 @@ static int meth_get_domainkey(struct tra
     static struct buf pathbuf = BUF_INITIALIZER;
     struct stat sbuf;
     const char *msg_base = NULL;
-    unsigned long msg_size = 0;
+    size_t msg_size = 0;
     struct resp_body_t *resp_body = &txn->resp_body;
 
     /* See if file exists and get Content-Length & Last-Modified time */
