$NetBSD$

* include stdlib.h for calloc(3)

--- demos/unsupported/xmform/xmform.c.orig	2016-03-16 02:10:08.000000000 +0000
+++ demos/unsupported/xmform/xmform.c
@@ -54,6 +54,7 @@ xmform*bottomShadowColor:        black
 #include <Xm/Form.h>
 #include <Xm/PushB.h>
 #include <Xm/ArrowB.h>
+#include <stdlib.h>
 
 static void FillItPlease();
 static void NearlyEvenSpread();
