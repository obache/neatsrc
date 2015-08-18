$NetBSD$

--- services/plugins/dndcp/dnd/dndLinux.c.orig	2015-06-17 16:14:30.000000000 +0000
+++ services/plugins/dndcp/dnd/dndLinux.c
@@ -39,7 +39,7 @@
 #include "util.h"
 #include "escape.h"
 #include "su.h"
-#if defined(linux) || defined(sun) || defined(__FreeBSD__)
+#if defined(linux) || defined(sun) || defined(__FreeBSD__) || defined(__NetBSD__)
 #include "vmblock_user.h"
 #include "mntinfo.h"
 #endif
@@ -311,7 +311,7 @@ DnD_UriIsNonFileSchemes(const char *uri)
 
 
 /* We need to make this suck less. */
-#if defined(linux) || defined(sun) || defined(__FreeBSD__)
+#if defined(linux) || defined(sun) || defined(__FreeBSD__) || defined(__NetBSD__)
 
 /*
  *----------------------------------------------------------------------------
@@ -771,7 +771,7 @@ DnD_CompleteBlockInitialization(int fd, 
    return TRUE;
 }
 
-#endif /* linux || sun || FreeBSD */
+#endif /* linux || sun || FreeBSD || NetBSD */
 
 
 /*
