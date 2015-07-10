$NetBSD$

* NULL != 0 in C++

--- src/storage/phrase_index.cpp.orig	2015-06-16 08:46:32.000000000 +0000
+++ src/storage/phrase_index.cpp
@@ -624,7 +624,7 @@ int SubPhraseIndex::get_range(/* out */ 
     /* remove trailing zeros. */
     const table_offset_t * poffset = NULL;
     for (poffset = end; poffset > begin + 1; --poffset) {
-        if (NULL !=  *(poffset - 1))
+        if (0 !=  *(poffset - 1))
             break;
     }
 
