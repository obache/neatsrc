$NetBSD: patch-camlibs_ax203_jpeg__memsrcdest.h,v 1.1 2016/02/04 11:57:50 wiz Exp $

Fix build with jpeg-9b.

--- camlibs/ax203/jpeg_memsrcdest.h.orig	2012-12-13 08:49:31.000000000 +0000
+++ camlibs/ax203/jpeg_memsrcdest.h
@@ -1,9 +1,13 @@
 #include <jpeglib.h>
 
+#if JPEG_LIB_VERSION < 80 && !defined(MEM_SRCDST_SUPPORTED)
+
 void
-jpeg_mem_src (j_decompress_ptr cinfo, unsigned char * buffer,
+jpeg_mem_src (j_decompress_ptr cinfo, const unsigned char * buffer,
 	unsigned long bufsize);
 
 void
 jpeg_mem_dest (j_compress_ptr cinfo, unsigned char ** outbuffer,
 	unsigned long * outsize);
+
+#endif
