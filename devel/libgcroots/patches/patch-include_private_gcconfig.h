$NetBSD: patch-include_private_gcconfig.h,v 1.1 2019/11/20 21:24:33 maya Exp $

Add support for netbsd/aarch64, based on netbsd/arm32 code within the same file.

--- include/private/gcconfig.h.orig	2018-05-10 01:31:47.000000000 +0000
+++ include/private/gcconfig.h
@@ -64,7 +64,7 @@
 /* Determine the machine type: */
 # if defined(__aarch64__)
 #    define AARCH64
-#    if !defined(LINUX)
+#    if !defined(LINUX) && !defined(NETBSD)
 #      define NOSYS
 #      define mach_type_known
 #    endif
@@ -106,6 +106,10 @@
 #    define ARM32
 #    define mach_type_known
 # endif
+# if defined(NETBSD) && defined(__aarch64__)
+#    define AARCH64
+#    define mach_type_known
+# endif
 # if defined(NETBSD) && defined(__sh__)
 #    define SH
 #    define mach_type_known
@@ -1752,6 +1756,15 @@
       extern char _end[];
 #     define DATAEND ((ptr_t)(&_end))
 #   endif
+#   ifdef NETBSD
+#     define OS_TYPE "NETBSD"
+#     define HEURISTIC2
+#     define DATASTART GC_data_start
+#     define ELFCLASS32 32
+#     define ELFCLASS64 64
+#     define ELF_CLASS ELFCLASS64
+#     define DYNAMIC_LOADING
+#   endif
 #   ifdef NOSYS
       /* __data_start is usually defined in the target linker script.   */
       extern int __data_start[];
