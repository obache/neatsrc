$NetBSD: patch-src-post-planar-noise.c,v 1.5 2018/11/19 12:48:32 jperkin Exp $

Disable MMX sections on SunOS.

--- src/post/planar/noise.c.orig	2018-01-11 12:49:47.000000000 +0000
+++ src/post/planar/noise.c
@@ -141,7 +141,7 @@ static inline void lineNoise_C(uint8_t *
     }
 }
 
-#ifdef ARCH_X86
+#if defined(ARCH_X86) && !defined(__sun)
 
 #if defined(ARCH_X86_64)
 #  define TYPEA int64_t
@@ -231,7 +231,7 @@ static inline void lineNoiseAvg_C(uint8_
     }
 }
 
-#ifdef ARCH_X86
+#if defined(ARCH_X86) && !defined(__sun)
 
 static inline void lineNoiseAvg_MMX(uint8_t *dst, uint8_t *src, int len, int8_t **shift){
   TYPEA mmx_len = len & (~7);
@@ -467,7 +467,7 @@ void *noise_init_plugin(xine_t *xine, vo
     class->description     = N_("Adds noise");
     class->dispose         = default_post_class_dispose;
 
-#ifdef ARCH_X86
+#if defined(ARCH_X86) && !defined(__sun)
     if (xine_mm_accel() & MM_ACCEL_X86_MMX) {
         lineNoise = lineNoise_MMX;
         lineNoiseAvg = lineNoiseAvg_MMX;
@@ -587,7 +587,7 @@ static int noise_draw(vo_frame_t *frame,
               frame->width * 2, frame->height, &this->params[0]);
     }
 
-#ifdef ARCH_X86
+#if defined(ARCH_X86) && !defined(__sun)
     if (xine_mm_accel() & MM_ACCEL_X86_MMX)
         __asm__ __volatile__ ("emms\n\t");
     if (xine_mm_accel() & MM_ACCEL_X86_MMXEXT)
