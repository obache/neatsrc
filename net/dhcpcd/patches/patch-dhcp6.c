$NetBSD$

* Fix for missing O_CLOEXEC

--- dhcp6.c.orig	2016-01-20 19:08:12.000000000 +0000
+++ dhcp6.c
@@ -3124,7 +3124,7 @@ dhcp6_open(struct dhcpcd_ctx *dctx)
 
 	ctx = dctx->ipv6;
 	ctx->dhcp_fd = xsocket(PF_INET6, SOCK_DGRAM, IPPROTO_UDP,
-	    O_NONBLOCK|O_CLOEXEC);
+	    SOCK_NONBLOCK|SOCK_CLOEXEC);
 	if (ctx->dhcp_fd == -1)
 		return -1;
 
