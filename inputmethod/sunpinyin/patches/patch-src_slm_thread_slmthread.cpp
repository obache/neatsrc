$NetBSD$

--- src/slm/thread/slmthread.cpp.orig	2016-05-08 13:57:00.000000000 +0000
+++ src/slm/thread/slmthread.cpp
@@ -253,7 +253,7 @@ main(int argc, char* argv[])
 
     bool usingLogPr = slm.isUseLogPr();
 
-    #define EffectivePr(a)  (usingLogPr ? ((a) / log(2.0)) : -log2f((a)))
+    #define EffectivePr(a)  (usingLogPr ? ((a) / log(2.0)) : -log2((a)))
     #define OriginalPr(b)   (usingLogPr ? ((b) * log(2.0)) : exp2(-(b)))
     #define EffectiveBow(a) (usingLogPr ? exp(-(a)) : (a))
     #define OriginalBow(b)  (usingLogPr ? -log((b)) : (b))
