$NetBSD$

* type mismatch

--- dvsend/rtcp.c.orig	2008-03-12 10:28:07.000000000 +0000
+++ dvsend/rtcp.c
@@ -107,7 +107,7 @@ process_rtcp (struct dvsend_param *dvsen
   rtcp_common_t *rtcp_hdr;
   int n;
   struct sockaddr_storage from;
-  int length = sizeof(from);
+  socklen_t length = sizeof(from);
 
   struct rtcp_recv_obj *rtcp_recv_obj;
 
