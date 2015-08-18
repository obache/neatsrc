$NetBSD$

--- lib/include/vmblock_user.h.orig	2015-06-17 16:14:30.000000000 +0000
+++ lib/include/vmblock_user.h
@@ -67,6 +67,9 @@
 
 #include "vm_basic_types.h"
 #include "vmblock.h"
+#if defined(__NetBSD__)
+#include <sys/ioctl.h>
+#endif
 
 static INLINE int
 VMBLOCK_CONTROL_FUSE(int fd,            // IN
@@ -125,7 +128,7 @@ VMBLOCK_CONTROL(int fd, int op, const ch
    return write(fd, path, op);
 }
 
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
 
 static INLINE int
 VMBLOCK_CONTROL(int fd, int cmd, const char *path)
