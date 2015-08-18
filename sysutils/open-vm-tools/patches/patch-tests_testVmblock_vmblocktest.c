$NetBSD$

--- tests/testVmblock/vmblocktest.c.orig	2015-06-17 16:14:30.000000000 +0000
+++ tests/testVmblock/vmblocktest.c
@@ -24,7 +24,7 @@
  *
  */
 
-#if !defined(linux) && !defined(sun) && !defined(__FreeBSD__) && !defined(vmblock_fuse)
+#if !defined(linux) && !defined(sun) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(vmblock_fuse)
 # error "vmblocktest.c needs to be ported to your OS."
 #endif
 
@@ -76,7 +76,7 @@
 #define THREAD_LOG(fmt, args...)   lprintf(" (%lx) " fmt, (unsigned long)pthread_self(), ## args)
 #define THREAD_ERROR(fmt, args...) lfprintf(stderr, " (%"FMTPID") " fmt, getpid(), ## args)
 
-#if defined (linux) || defined(__FreeBSD__)
+#if defined (linux) || defined(__FreeBSD__) || defined(__NetBSD__)
 # define os_thread_yield()      sched_yield()
 #elif defined(sun)
 # define os_thread_yield()      yield()
