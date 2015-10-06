$NetBSD$

* using C str* functions

--- src/ukengine/usrkeymap.cpp.orig	2006-04-08 23:31:40.000000000 +0000
+++ src/ukengine/usrkeymap.cpp
@@ -23,6 +23,7 @@
 
 #include "stdafx.h"
 #include <iostream>
+#include <cstring>
 using namespace std;
 
 #include <ctype.h>
