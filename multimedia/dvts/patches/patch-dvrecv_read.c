$NetBSD$

* type mismatch

--- dvrecv/read.c.orig	2008-03-12 10:28:07.000000000 +0000
+++ dvrecv/read.c
@@ -78,7 +78,7 @@ void
 dvrtp_read_loop (struct dvrecv_param *dvrecv_param)
 {
   struct sockaddr_storage from;
-  int length = sizeof(from);
+  socklen_t length = sizeof(from);
   int n;
   int i;
 
