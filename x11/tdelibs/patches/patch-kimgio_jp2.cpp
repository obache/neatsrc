$NetBSD$

* unistd.h for dup(2)

--- kimgio/jp2.cpp.orig	2020-04-10 23:08:30.000000000 +0000
+++ kimgio/jp2.cpp
@@ -15,6 +15,9 @@
 #ifdef HAVE_STDINT_H
 #include <stdint.h>
 #endif
+#ifdef HAVE_UNISTD_H
+#include <unistd.h>
+#endif
 #include <tdetempfile.h>
 #include <tqcolor.h>
 #include <tqcstring.h>
