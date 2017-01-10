$NetBSD$

* type mismatch 

--- dvrecv/rtcp.c.orig	2008-03-12 10:28:07.000000000 +0000
+++ dvrecv/rtcp.c
@@ -135,7 +135,7 @@ process_rtcp (struct dvrecv_param *dvrec
   rtcp_common_t *rtcp_hdr;
   int n;
   struct sockaddr_storage from;
-  int length = sizeof(from);
+  socklen_t length = sizeof(from);
 
   if (!(dvrecv_param->flags & USE_RTCP)) {
     return(1);
