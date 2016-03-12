$NetBSD$

* Fix for missing O_CLOEXEC

--- dhcp6.c.orig	2016-01-20 19:08:12.000000000 +0000
+++ dhcp6.c
@@ -3123,8 +3123,9 @@ dhcp6_open(struct dhcpcd_ctx *dctx)
 #endif
 
 	ctx = dctx->ipv6;
-	ctx->dhcp_fd = xsocket(PF_INET6, SOCK_DGRAM, IPPROTO_UDP,
-	    O_NONBLOCK|O_CLOEXEC);
+#define SOCK_FLAGS	SOCK_CLOEXEC | SOCK_NONBLOCK
+	ctx->dhcp_fd = xsocket(PF_INET6, SOCK_DGRAM, IPPROTO_UDP, SOCK_FLAGS);
+#undef SOCK_FLAGS
 	if (ctx->dhcp_fd == -1)
 		return -1;
 
