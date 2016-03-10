$NetBSD$

* Fix for missing O_CLOEXEC

--- control.c.orig	2016-01-20 19:08:12.000000000 +0000
+++ control.c
@@ -208,7 +208,7 @@ make_sock(struct sockaddr_un *sa, const 
 {
 	int fd;
 
-	if ((fd = xsocket(AF_UNIX, SOCK_STREAM, 0, O_NONBLOCK|O_CLOEXEC)) == -1)
+	if ((fd = xsocket(AF_UNIX, SOCK_STREAM, 0, SOCK_NONBLOCK|SOCK_CLOEXEC)) == -1)
 		return -1;
 	memset(sa, 0, sizeof(*sa));
 	sa->sun_family = AF_UNIX;
