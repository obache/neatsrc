$NetBSD$

--- src/network/qdns.cpp.orig	2020-04-10 10:04:43.000000000 +0000
+++ src/network/qdns.cpp
@@ -102,7 +102,7 @@ static TQ_UINT32 now()
     return 0;
 }
 
-#if defined(__GLIBC__) && ((__GLIBC__ > 2) || ((__GLIBC__ == 2) && (__GLIBC_MINOR__ >= 3)))
+#if defined(__RES) && (__RES >= 19980901)
 #define Q_MODERN_RES_API
 #else
 #endif
