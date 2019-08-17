$NetBSD$

* fix PIC issues from Portage

--- video/mmxflags_asm.S.orig	2000-04-05 23:12:20.000000000 +0000
+++ video/mmxflags_asm.S
@@ -1,11 +1,6 @@
 
 #if defined(i386) && defined(USE_MMX)
 
-.data
-	.align 16
-	.type	 flags,@object
-flags: .long 0
-
 .text
 	.align 4
 .globl cpu_flags
@@ -40,16 +35,13 @@ cpu_flags: 
         xorl %ecx,%eax
         je cpu_flags.L1
 
-        pusha
+        pushl %ebx
 
         movl $1,%eax
         cpuid
+        movl %edx,%eax
 
-        movl %edx,flags
-
-        popa
-
-        movl flags,%eax
+        popl %ebx
 
 cpu_flags.L1: 
         ret
