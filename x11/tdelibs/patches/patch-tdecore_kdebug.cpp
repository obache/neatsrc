$NetBSD$

--- tdecore/kdebug.cpp.orig	2020-04-10 23:08:30.000000000 +0000
+++ tdecore/kdebug.cpp
@@ -59,7 +59,11 @@
 #include <config.h>
 
 #ifdef HAVE_BACKTRACE
-#include <execinfo.h>
+#include BACKTRACE_H
+
+#ifdef HAVE_DLFCN_H
+#include <dlfcn.h>
+#endif
 
 #ifdef HAVE_ABI_CXA_DEMANGLE
 #include <cxxabi.h>
