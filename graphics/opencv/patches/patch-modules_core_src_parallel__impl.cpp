$NetBSD$

* include required file for __mm_pause()

--- modules/core/src/parallel_impl.cpp.orig	2019-04-06 21:43:23.000000000 +0000
+++ modules/core/src/parallel_impl.cpp
@@ -53,6 +53,12 @@ DECLARE_CV_PAUSE
 #   if !defined(__SSE__)
       static inline void cv_non_sse_mm_pause() { __asm__ __volatile__ ("rep; nop"); }
 #     define _mm_pause cv_non_sse_mm_pause
+#   else 
+#     if defined( __MINGW64__ )
+#       include <intrin.h>
+#     else
+#        include <xmmintrin.h>
+#     endif
 #   endif
 #   define CV_PAUSE(v) do { for (int __delay = (v); __delay > 0; --__delay) { _mm_pause(); } } while (0)
 # elif defined __GNUC__ && defined __aarch64__
