$NetBSD: patch-include_sj3compat_sj3vis.h,v 1.1 2013/11/05 17:39:46 joerg Exp $

* __bounded__ attribute is a OpenBSD local extension, and this codes
  should not be used on OpenBSD because of BSD44 compat.

--- include/sj3compat/sj3vis.h.orig	2013-11-05 07:44:11.000000000 +0000
+++ include/sj3compat/sj3vis.h
@@ -81,14 +81,11 @@
 
 char	*vis(char *, int, int, int);
 int	strvis(char *, const char *, int);
-int	strnvis(char *, const char *, size_t, int)
-		__attribute__ ((__bounded__(__string__,1,3)));
-int	strvisx(char *, const char *, size_t, int)
-		__attribute__ ((__bounded__(__string__,1,3)));
+int	strnvis(char *, const char *, size_t, int);
+int	strvisx(char *, const char *, size_t, int);
 int	strunvis(char *, const char *);
 int	unvis(char *, char, int *, int);
-ssize_t strnunvis(char *, const char *, size_t)
-		__attribute__ ((__bounded__(__string__,1,3)));
+ssize_t strnunvis(char *, const char *, size_t);
 
 #endif /* !_VIS_H_ */
 
