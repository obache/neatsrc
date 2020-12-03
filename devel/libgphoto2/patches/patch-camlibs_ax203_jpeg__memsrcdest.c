$NetBSD: patch-camlibs_ax203_jpeg__memsrcdest.c,v 1.1 2016/02/04 11:57:50 wiz Exp $

Fix build with jpeg-9b.

--- camlibs/ax203/jpeg_memsrcdest.c.orig	2012-12-13 08:49:31.000000000 +0000
+++ camlibs/ax203/jpeg_memsrcdest.c
@@ -25,8 +25,8 @@
 #include "jpeg_memsrcdest.h"
 
 /* libjpeg8 and later come with their own (API compatible) memory source
-   and dest */
-#if JPEG_LIB_VERSION < 80
+   and dest, and older versions may have it backported */
+#if JPEG_LIB_VERSION < 80 && !defined(MEM_SRCDST_SUPPORTED)
 
 /* Expanded data source object for memory input */
 
@@ -143,7 +143,7 @@ term_source (j_decompress_ptr cinfo)
 */
 
 GLOBAL(void)
-jpeg_mem_src (j_decompress_ptr cinfo, unsigned char * buffer,
+jpeg_mem_src (j_decompress_ptr cinfo, const unsigned char * buffer,
 	unsigned long bufsize)
 {
 	my_src_ptr src;
