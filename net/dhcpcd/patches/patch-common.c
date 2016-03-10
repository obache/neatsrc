$NetBSD$

* Fix F_GETFD usage

--- common.c.orig	2016-01-20 19:08:12.000000000 +0000
+++ common.c
@@ -69,7 +69,7 @@ logger_open(struct dhcpcd_ctx *ctx)
 			warn("open: %s", ctx->logfile);
 #ifndef O_CLOEXEC
 		else {
-			if (fcntl(ctx->log_fd, F_GETFD, &f) == -1 ||
+			if ((f = fcntl(ctx->log_fd, F_GETFD)) == -1 ||
 			    fcntl(ctx->log_fd, F_SETFD, f | FD_CLOEXEC) == -1)
 				warn("fcntl: %s", ctx->logfile);
 		}
