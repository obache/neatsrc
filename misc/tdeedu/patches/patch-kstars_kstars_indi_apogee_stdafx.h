$NetBSD$

--- kstars/kstars/indi/apogee/stdafx.h.orig	2020-04-10 23:08:26.000000000 +0000
+++ kstars/kstars/indi/apogee/stdafx.h
@@ -10,7 +10,6 @@
 #if !defined(STDAFX__INCLUDED_)
 #define STDAFX__INCLUDED_
 
-#ifdef __linux__
 #include <stdlib.h>
 #include <stdio.h>
 #include <unistd.h>
@@ -18,6 +17,7 @@
 #define ULONG unsigned long
 #define USHORT unsigned short
 #define PUSHORT unsigned short *
+#ifdef __linux__
 #define BYTE unsigned char
 #define DWORD long
 #define BOOLEAN unsigned long
@@ -27,16 +27,7 @@
 #define INTERNET_FLAG_NO_CACHE_WRITE 1
 #define INTERNET_FLAG_KEEP_CONNECTION 1
 #define Sleep(x) usleep(1000*x)
-#endif
-
-#ifdef __FreeBSD__
-#include <stdlib.h>
-#include <stdio.h>
-#include <unistd.h>
-#include <string.h>
-#define ULONG unsigned long
-#define USHORT unsigned short
-#define PUSHORT unsigned short *
+#else
 #define Sleep(x) sleep(x)
 #endif
 
