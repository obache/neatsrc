$NetBSD$

* Using C str*(3) functions

--- uvconvert/uvconvert.cpp.orig	2004-07-25 20:19:18.000000000 +0000
+++ uvconvert/uvconvert.cpp
@@ -21,6 +21,7 @@ Foundation, Inc., 59 Temple Place - Suit
 
 #include "prehdr.h"
 #include "vnconv.h"
+#include <cstring>
 
 using namespace std;
 
