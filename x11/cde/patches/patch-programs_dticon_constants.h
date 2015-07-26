$NetBSD$

--- programs/dticon/constants.h.orig	2015-05-09 23:09:11.000000000 +0000
+++ programs/dticon/constants.h
@@ -97,7 +97,7 @@ typedef struct {
 #define min(a, b)	((a < b) ? a : b)
 #define max(a, b)	((a > b) ? a : b)
 #ifndef abs
-#if !defined(linux)
+#if !defined(linux) || !defined(__NetBSD__)
 #define abs(a)		(((a) < 0) ? -(a) : (a))
 #endif
 #endif
