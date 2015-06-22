$NetBSD$

* Treat NetBSD same as OpenBSD 

--- src/procproperties.cpp.orig	2015-01-22 08:31:04.000000000 +0000
+++ src/procproperties.cpp
@@ -26,7 +26,7 @@
 #include <glibtop/procstate.h>
 #if defined (__linux__)
 #include <asm/param.h>
-#elif defined (__OpenBSD__)
+#elif defined (__NetBSD__) || defined (__OpenBSD__)
 #include <sys/param.h>
 #include <sys/sysctl.h>
 #endif
@@ -114,7 +114,7 @@ fill_proc_properties (GtkWidget *tree, P
 
     get_process_memory_info(info);
 
-#if defined (__OpenBSD__)
+#if defined (__NetBSD__) || defined (__OpenBSD__)
     struct clockinfo cinf;
     size_t size = sizeof (cinf);
     int HZ;
