$NetBSD$

* Fix for missing O_CLOEXEC

--- ipv6nd.c.orig	2016-01-20 19:08:12.000000000 +0000
+++ ipv6nd.c
@@ -190,7 +190,7 @@ ipv6nd_open(struct dhcpcd_ctx *dctx)
 	if (ctx->nd_fd != -1)
 		return ctx->nd_fd;
 	ctx->nd_fd = xsocket(PF_INET6, SOCK_RAW, IPPROTO_ICMPV6,
-	    O_NONBLOCK|O_CLOEXEC);
+	    SOCK_NONBLOCK|SOCK_CLOEXEC);
 	if (ctx->nd_fd == -1)
 		return -1;
 
