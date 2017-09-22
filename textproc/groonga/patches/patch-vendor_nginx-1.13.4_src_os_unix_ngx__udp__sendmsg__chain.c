$NetBSD$

* NetBSD does not support ipi_spec_dst in in_pktinfo  

--- vendor/nginx-1.13.4/src/os/unix/ngx_udp_sendmsg_chain.c.orig	2017-05-25 03:16:55.000000000 +0000
+++ vendor/nginx-1.13.4/src/os/unix/ngx_udp_sendmsg_chain.c
@@ -271,7 +271,11 @@ ngx_sendmsg(ngx_connection_t *c, ngx_iov
 
             pkt = (struct in_pktinfo *) CMSG_DATA(cmsg);
             ngx_memzero(pkt, sizeof(struct in_pktinfo));
+#if defined(__NetBSD__)
+            pkt->ipi_addr = sin->sin_addr;
+#else
             pkt->ipi_spec_dst = sin->sin_addr;
+#endif
         }
 
 #endif
