$NetBSD$

# PHP bug #74527 - segfaults on build with GCC 4.8.5 i386

--- Zend/Zend.m4.orig	2018-03-28 07:11:56.000000000 +0000
+++ Zend/Zend.m4
@@ -426,7 +426,7 @@ if test "$ZEND_GCC_GLOBAL_REGS" != "no";
 #else
 # define ZEND_GCC_VERSION 0
 #endif
-#if defined(__GNUC__) && ZEND_GCC_VERSION >= 4008 && defined(i386)
+#if defined(__GNUC__) && ZEND_GCC_VERSION >= 4009 && defined(i386)
 # define ZEND_VM_FP_GLOBAL_REG "%esi"
 # define ZEND_VM_IP_GLOBAL_REG "%edi"
 #elif defined(__GNUC__) && ZEND_GCC_VERSION >= 4008 && defined(__x86_64__)
