$NetBSD$

--- lib/file/file.c.orig	2015-06-17 16:14:30.000000000 +0000
+++ lib/file/file.c
@@ -1502,7 +1502,7 @@ File_MoveTree(ConstUnicode srcName,   //
          }
       }
 
-#if !defined(__FreeBSD__) && !defined(sun)
+#if !defined(__FreeBSD__) && !defined(sun) && !defined(__NetBSD__)
       /*
        * File_GetFreeSpace is not defined for FreeBSD
        */
