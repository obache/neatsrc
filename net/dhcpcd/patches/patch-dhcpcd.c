$NetBSD$

* Fix F_GETFD usage

--- dhcpcd.c.orig	2016-01-20 19:08:12.000000000 +0000
+++ dhcpcd.c
@@ -1834,7 +1834,7 @@ printpidfile:
 			}
 #endif
 #ifndef O_CLOEXEC
-			if (fcntl(ctx.pid_fd, F_GETFD, &opt) == -1 ||
+			if ((opt = fcntl(ctx.pid_fd, F_GETFD)) == -1 ||
 			    fcntl(ctx.pid_fd, F_SETFD, opt | FD_CLOEXEC) == -1)
 			{
 				logger(&ctx, LOG_ERR, "fcntl: %m");
