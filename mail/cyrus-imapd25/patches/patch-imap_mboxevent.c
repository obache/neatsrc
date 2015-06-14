$NetBSD$

--- imap/mboxevent.c.orig	2015-05-08 03:49:52.000000000 +0000
+++ imap/mboxevent.c
@@ -820,7 +820,7 @@ void mboxevent_extract_content(struct mb
 			       const struct index_record *record, FILE* content)
 {
     const char *base = NULL;
-    unsigned long len = 0;
+    size_t len = 0;
     size_t offset, size, truncate;
 
     if (!event)
