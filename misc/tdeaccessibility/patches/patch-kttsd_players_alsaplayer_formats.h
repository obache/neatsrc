$NetBSD$

* endian support for NetBSD

--- kttsd/players/alsaplayer/formats.h.orig	2011-11-29 07:38:36.000000000 +0000
+++ kttsd/players/alsaplayer/formats.h
@@ -1,8 +1,12 @@
 #ifndef FORMATS_H
 #define FORMATS_H		1
 
+#ifdef __NetBSD__
+#include <sys/endian.h>
+#else
 #include <endian.h>
 #include <byteswap.h>
+#endif
 
 /* Definitions for .VOC files */
 
@@ -44,6 +48,19 @@ typedef struct voc_ext_block {
 
 /* Definitions for Microsoft WAVE format */
 
+#ifdef __NetBSD__
+#if _BYTE_ORDER == _LITTLE_ENDIAN
+#define COMPOSE_ID(a,b,c,d)	((a) | ((b)<<8) | ((c)<<16) | ((d)<<24))
+#elif _BYTE_ORDER == _BIG_ENDIAN
+#define COMPOSE_ID(a,b,c,d)	((d) | ((c)<<8) | ((b)<<16) | ((a)<<24))
+#else
+#error "Unknown endian"
+#endif
+#define LE_SHORT(v)		htole16(v)
+#define LE_INT(v)		htole32(v)
+#define BE_SHORT(v)		htobe16(v)
+#define BE_INT(v)		htobe32(v)
+#else
 #if __BYTE_ORDER == __LITTLE_ENDIAN
 #define COMPOSE_ID(a,b,c,d)	((a) | ((b)<<8) | ((c)<<16) | ((d)<<24))
 #define LE_SHORT(v)		(v)
@@ -59,6 +76,7 @@ typedef struct voc_ext_block {
 #else
 #error "Wrong endian"
 #endif
+#endif
 
 #define WAV_RIFF		COMPOSE_ID('R','I','F','F')
 #define WAV_WAVE		COMPOSE_ID('W','A','V','E')
