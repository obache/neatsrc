$NetBSD: patch-libf95.a-0.93_math_x87.S,v 1.2 2015/12/29 23:34:46 dholland Exp $

Fix assembler instructions.

--- libf95.a-0.93/math/x87.S.orig	2010-04-04 18:49:02.000000000 +0000
+++ libf95.a-0.93/math/x87.S
@@ -36,8 +36,18 @@
 #define SIGNX_AL   movsbl %al, %eax
 #define SIGNX_AX   movswl %ax, %eax
 
+#ifdef __PIC__
+#define HALF half ## @GOTOFF(%ebx)
+#define INFINITY infinity ## @GOTOFF(%ebx)
+#undef __i686
+#define INIT_PIC() \
+	call __i686.get_pc_thunk.bx ; \
+	addl $_GLOBAL_OFFSET_TABLE_, %ebx
+#else
 #define HALF half
 #define INFINITY infinity	
+#define INIT_PIC()
+#endif
 
 #endif
 
@@ -200,6 +210,7 @@ PUBLIC(g95_anint10_4)
 	fldcw   (SP)          # x
 	fxam
 	fnstsw  %ax
+	INIT_PIC()
 	flds	HALF          # 0.5 . x
 	test    $0x02, %ah
 	je      1f
@@ -250,7 +261,7 @@ PUBLIC(g95_ceiling_1_r10)
 	fldcw	(SP)
 	frndint
 	fldcw	4(SP)
-	fistp	(SP)
+	fistps	(SP)
 	mov	(SP), %al
 	SIGNX_AL
 	add	$8, SP
@@ -266,7 +277,7 @@ PUBLIC(g95_ceiling_2_r10)
 	fldcw	(SP)
 	frndint
 	fldcw	4(SP)
-	fistp	(SP)
+	fistps	(SP)
 	mov	(SP), %ax
 	SIGNX_AX
 	add	$8, SP
@@ -406,6 +417,7 @@ cosh_10:
 # Finite x
 0:	sub	$16, SP
 
+	INIT_PIC()
 	fldln2			# ln2
 	fmuls	HALF		# 0.5*ln2
 
@@ -491,6 +503,7 @@ sinh_10:fxam
 	movb	$0x45, %al
 	andb	%ah, %al
 	cmpb	$0x05, %al
+	INIT_PIC()
 	jne	0f
 	ret
 
@@ -675,7 +688,7 @@ PUBLIC(g95_floor_1_r10)
 	fldcw	(SP)
 	frndint
 	fldcw	4(SP)
-	fistp	(SP)
+	fistps	(SP)
 	mov	(SP), %al
 	SIGNX_AL
 	add	$8, SP
@@ -691,7 +704,7 @@ PUBLIC(g95_floor_2_r10)
 	fldcw	(SP)
 	frndint
 	fldcw	4(SP)
-	fistp	(SP)
+	fistps	(SP)
 	mov	(SP), %ax
 	SIGNX_AX
 	add	$8, SP
@@ -820,6 +833,7 @@ PUBLIC(g95_nint_1_r10)
 	fnstcw  4(SP)
 	movw	$0xf7f, (SP)
 	fldcw	(SP)
+	INIT_PIC()
 	flds	HALF
 	fxch	%st(1)
 	fxam
@@ -833,7 +847,7 @@ PUBLIC(g95_nint_1_r10)
 	frndint
 	fldcw	4(SP)
 
-	fistp	(SP)
+	fistps	(SP)
 	movb	(SP), %al
 	SIGNX_AL
 	add	$8, SP
@@ -848,6 +862,7 @@ PUBLIC(g95_nint_2_r10)
 	fnstcw	4(SP)
 	movw	$0xf7f, (SP)
 	fldcw	(SP)
+	INIT_PIC()
 	flds	HALF
 	fxch	%st(1)
 	fxam
@@ -861,7 +876,7 @@ PUBLIC(g95_nint_2_r10)
 	frndint
 	fldcw	4(SP)
 
-	fistp	(SP)
+	fistps	(SP)
 	movw	(SP), %ax
 	SIGNX_AX
 	add	$8, SP
@@ -876,6 +891,7 @@ PUBLIC(g95_nint_4_r10)
 	fnstcw	4(SP)
 	movw	$0xf7f, (SP)
 	fldcw	(SP)
+	INIT_PIC()
 	flds	HALF
 	fxch	%st(1)
 	fxam
@@ -903,6 +919,7 @@ PUBLIC(g95_nint_8_r10)
 	fnstcw	4(SP)
 	movw	$0xf7f, (SP)
 	fldcw	(SP)
+	INIT_PIC()
 	flds	HALF	
 	fxch	%st(1)
 	fxam
@@ -1039,6 +1056,7 @@ PUBLIC(g95_sqrt_z10)
 	fcomp	%st(2)		# mag . r . c
 	fstsw
 
+	INIT_PIC()
 	andb	$0x41, %ah
 	jz	1f
 
@@ -1289,7 +1307,8 @@ check_x:
 	stc
 	ret
 
-4:	flds	INFINITY
+4:	INIT_PIC()
+	flds	INFINITY
 	stc
 	ret
 
@@ -1585,7 +1604,8 @@ PUBLIC(g95_power_r10)
 	fldz
 	ret
 
-8:	flds	INFINITY	# Single +Infinity
+8:	INIT_PIC()
+	flds	INFINITY	# Single +Infinity
 	ret
 
 # General exponentiation
@@ -1917,3 +1937,13 @@ PUBLIC(g95_power_z10_i8)
 	fstpt	IMAG(REGAX)
 	fstpt	(REGAX)
 	ret
+
+#ifdef __PIC__
+	.section .gnu.linkonce.t.__i686.get_pc_thunk.bx,"ax",@progbits
+.globl __i686.get_pc_thunk.bx
+	.hidden	__i686.get_pc_thunk.bx
+	.type	__i686.get_pc_thunk.bx,@function
+__i686.get_pc_thunk.bx:
+	movl (%esp), %ebx
+	ret
+#endif
