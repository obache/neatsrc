$NetBSD$

* <sys/select.h> for select(2)

--- src/sj3proxy/sj3proxy.c.orig	2010-02-14 12:20:34.000000000 +0000
+++ src/sj3proxy/sj3proxy.c
@@ -80,6 +80,9 @@
 #else
 # include <sj3vis.h>
 #endif
+#if defined(HAVE_SYS_SELECT_H)
+#include <sys/select.h>
+#endif
 #include "sys-queue.h"
 
 #include <lua.h>
