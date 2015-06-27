$NetBSD$

* Use g_malloc instead of malloc to be safe

--- libcaja-private/caja-undostack-manager.c.orig	2015-06-11 20:59:47.000000000 +0000
+++ libcaja-private/caja-undostack-manager.c
@@ -903,7 +903,7 @@ caja_undostack_manager_data_add_trashed_
     return;
 
   guint64 *modificationTime;
-  modificationTime = (guint64 *) malloc (sizeof (guint64));
+  modificationTime = (guint64 *) g_malloc (sizeof (guint64));
   *modificationTime = mtime;
 
   char *originalURI = g_file_get_uri (file);
@@ -924,7 +924,7 @@ void caja_undostack_manager_data_add_fil
     return;
 
   guint32 *currentPermission;
-  currentPermission = (guint32 *) malloc (sizeof (guint32));
+  currentPermission = (guint32 *) g_malloc (sizeof (guint32));
   *currentPermission = permission;
 
   char *originalURI = g_file_get_uri (file);
