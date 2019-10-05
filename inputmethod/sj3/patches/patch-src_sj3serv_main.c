$NetBSD$

* fix missing function type

--- src/sj3serv/main.c.orig	2010-02-14 12:20:33.000000000 +0000
+++ src/sj3serv/main.c
@@ -90,6 +90,7 @@ terminate_handler(int sig)
 	server_terminate();
 }
 
+static int
 sigchild_handler(int sig)
 {
 	int save_errno = errno;
