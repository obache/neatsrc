$NetBSD$

--- lib/DtSearch/SearchP.h.orig	2019-10-12 21:43:45.000000000 +0000
+++ lib/DtSearch/SearchP.h
@@ -522,6 +522,10 @@ typedef enum {HTON=1, NTOH} SWABDIR;
 extern void swab_dbrec  (struct or_dbrec  *rec,  SWABDIR direction);
 extern void swab_objrec (struct or_objrec *rec,  SWABDIR direction);
 
+#ifdef __NetBSD__
+#include <sys/endian.h>
+#else
+
 #ifdef BYTE_SWAP	/* ie (BYTE_ORDER != BIG_ENDIAN) */
 
 #define HTONL(x)	x = htonl(x)
@@ -538,6 +542,7 @@ extern void swab_objrec (struct or_objre
 
 #endif /* BYTE_SWAP */
 
+#endif
 
 /*--------------- TESKEY PARSE CHARACTER TYPES ------------
  * Used in langmap.c for linguistic parsing modules.
