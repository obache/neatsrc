$NetBSD$

--- programs/dtmail/include/utils/MemUtils.hh.orig	2015-05-09 23:09:11.000000000 +0000
+++ programs/dtmail/include/utils/MemUtils.hh
@@ -72,7 +72,7 @@ grow_region(void * old_region, const int
     if (new_region) {
 	memcpy(new_region, old_region, old_size);
     }
-    delete old_region;
+    delete[] old_region;
     return(new_region);
 }
 
