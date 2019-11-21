$NetBSD$

* <wctype.h> for isw*()

--- programs/dtksh/ksh93/src/lib/libast/string/strmatch.c.orig	2019-11-16 02:06:11.000000000 +0000
+++ programs/dtksh/ksh93/src/lib/libast/string/strmatch.c
@@ -102,6 +102,7 @@
  #endif
 #endif
 #include <wchar.h>
+#include <wctype.h>
 
 #undef	isalnum
 #define isalnum(x)	iswalnum(x)
