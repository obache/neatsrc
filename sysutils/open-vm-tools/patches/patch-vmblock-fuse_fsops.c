$NetBSD$

--- vmblock-fuse/fsops.c.orig	2015-06-17 16:14:30.000000000 +0000
+++ vmblock-fuse/fsops.c
@@ -722,7 +722,7 @@ VMBlockRelease(const char *path,        
  */
 
 void *
-VMBlockInit(void)
+VMBlockInit(struct fuse_conn_info *conn)    // IN: Not used.
 {
    BlockInit();
    return NULL;
