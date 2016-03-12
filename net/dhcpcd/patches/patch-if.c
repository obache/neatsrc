$NetBSD$

* Fix for missing O_CLOEXEC

--- if.c.orig	2016-01-20 19:08:12.000000000 +0000
+++ if.c
@@ -93,19 +93,19 @@ if_opensockets(struct dhcpcd_ctx *ctx)
 		return -1;
 
 	/* We use this socket for some operations without INET. */
-	ctx->pf_inet_fd = xsocket(PF_INET, SOCK_DGRAM, 0, O_CLOEXEC);
+	ctx->pf_inet_fd = xsocket(PF_INET, SOCK_DGRAM, 0, SOCK_CLOEXEC);
 	if (ctx->pf_inet_fd == -1)
 		return -1;
 
 #if defined(INET6) && defined(BSD)
-	ctx->pf_inet6_fd = xsocket(PF_INET6, SOCK_DGRAM, 0, O_CLOEXEC);
+	ctx->pf_inet6_fd = xsocket(PF_INET6, SOCK_DGRAM, 0, SOCK_CLOEXEC);
 	/* Don't return an error so we at least work on kernels witout INET6
 	 * even though we expect INET6 support.
 	 * We will fail noisily elsewhere anyway. */
 #endif
 
 #ifdef IFLR_ACTIVE
-	ctx->pf_link_fd = xsocket(PF_LINK, SOCK_DGRAM, 0, O_CLOEXEC);
+	ctx->pf_link_fd = xsocket(PF_LINK, SOCK_DGRAM, 0, SOCK_CLOEXEC);
 	if (ctx->pf_link_fd == -1)
 		return -1;
 #endif
@@ -676,25 +676,35 @@ if_sortinterfaces(struct dhcpcd_ctx *ctx
 int
 xsocket(int domain, int type, int protocol, int flags)
 {
-#ifdef SOCK_CLOEXEC
-	if (flags & O_CLOEXEC)
+	int s;
+#if !defined(HAVE_SOCK_CLOEXEC) || !defined(HAVE_SOCK_NONBLOCK)
+	int xflags;
+#endif
+
+#ifdef HAVE_SOCK_CLOEXEC
+	if (flags & SOCK_CLOEXEC)
 		type |= SOCK_CLOEXEC;
-	if (flags & O_NONBLOCK)
+#endif
+#ifdef HAVE_SOCK_NONBLOCK
+	if (flags & SOCK_NONBLOCK)
 		type |= SOCK_NONBLOCK;
-
-	return socket(domain, type, protocol);
-#else
-	int s, xflags;
-
+#endif
 	if ((s = socket(domain, type, protocol)) == -1)
 		return -1;
-	if ((flags & O_CLOEXEC) && ((xflags = fcntl(s, F_GETFD, 0)) == -1 ||
+
+#ifndef HAVE_SOCK_CLOEXEC
+	if ((flags & SOCK_CLOEXEC) && ((xflags = fcntl(s, F_GETFD)) == -1 ||
 	    fcntl(s, F_SETFD, xflags | FD_CLOEXEC) == -1))
 		goto out;
-	if ((flags & O_NONBLOCK) && ((xflags = fcntl(s, F_GETFL, 0)) == -1 ||
+#endif
+#ifndef HAVE_SOCK_NONBLOCK
+	if ((flags & SOCK_NONBLOCK) && ((xflags = fcntl(s, F_GETFL)) == -1 ||
 	    fcntl(s, F_SETFL, xflags | O_NONBLOCK) == -1))
 		goto out;
+#endif
+
 	return s;
+#if !defined(HAVE_SOCK_CLOEXEC) || !defined(HAVE_SOCK_NONBLOCK)
 out:
 	close(s);
 	return -1;
