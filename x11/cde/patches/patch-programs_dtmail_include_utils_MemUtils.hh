$NetBSD$

--- programs/dtmail/include/utils/MemUtils.hh.orig	2019-11-16 02:06:11.000000000 +0000
+++ programs/dtmail/include/utils/MemUtils.hh
@@ -94,7 +94,7 @@ grow_region(void * old_region, const int
     if (new_region) {
         memcpy(new_region, old_region, old_size);
     }
-    delete (unsigned char*) old_region;
+    delete [] (unsigned char*) old_region;
     return(new_region);
 }
 
