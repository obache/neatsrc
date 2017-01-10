$NetBSD$

--- include/EUSCompat.h.orig	2015-05-09 23:09:11.000000000 +0000
+++ include/EUSCompat.h
@@ -114,7 +114,7 @@ typedef enum {B_FALSE, B_TRUE} boolean_t
 typedef enum {B_FALSE, B_TRUE} boolean_t;
 #define MAXNAMELEN      	256
 
-#if !defined(__FreeBSD__)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 #define iconv_t			int
 #define iconv_open(a, b) 	((iconv_t) -1)
 #define iconv(a, b, c, d, e)	((size_t) 0)
