$NetBSD$

--- lib/DtSearch/raima/dbswab.h.orig	2019-10-12 21:43:45.000000000 +0000
+++ lib/DtSearch/raima/dbswab.h
@@ -80,6 +80,10 @@ typedef enum {HTON=1, NTOH} SWABDIR;
 
 extern void	swab_page (char *pgbuf, FILE_ENTRY *file_ptr, SWABDIR direction);
 
+#ifdef __NetBSD__
+#include <sys/endian.h>
+#else
+
 #ifdef BYTE_SWAP  /* ie (BYTE_ORDER != BIG_ENDIAN) */
 
 #define HTONL(x)	x = htonl(x)
@@ -96,6 +100,8 @@ extern void	swab_page (char *pgbuf, FILE
 
 #endif	/* BYTE_SWAP */
 
+#endif
+
 /******** debug stuff *******/
 extern char	*debug_keyslot_ptr;
 extern void	snap_dump (char *label, void *ptr, int len);
