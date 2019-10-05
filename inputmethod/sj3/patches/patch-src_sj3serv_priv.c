$NetBSD$

* fix to match with return type

--- src/sj3serv/priv.c.orig	2010-02-14 12:43:30.000000000 +0000
+++ src/sj3serv/priv.c
@@ -288,7 +288,7 @@ priv_getugid(char *username, sj3_ugid *u
 
 	len = strlen(username) + 1;
 	if (len == 0 || BUFSIZ < len)
-		return NULL;
+		return 0;
 
 	must_write(auth_fd, &cmd, sizeof(int));
 	must_write(auth_fd, &len, sizeof(size_t));
