$NetBSD$

* write only here

--- compat/dprintf.c.orig	2016-01-20 19:08:12.000000000 +0000
+++ compat/dprintf.c
@@ -41,7 +41,7 @@ vdprintf(int fd, const char * __restrict
 	if ((e = dup(fd)) == -1)
 		return -1;
 
-	if ((fp = fdopen(e, "r+")) == NULL) {
+	if ((fp = fdopen(e, "w")) == NULL) {
 		close(e);
 		return -1;
 	}
