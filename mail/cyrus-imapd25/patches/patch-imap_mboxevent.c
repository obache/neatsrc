$NetBSD$

--- imap/mboxevent.c.orig	2016-07-22 01:55:57.000000000 +0000
+++ imap/mboxevent.c
@@ -826,8 +826,7 @@ void mboxevent_extract_content(struct mb
 			       const struct index_record *record, FILE* content)
 {
     const char *base = NULL;
-    unsigned long len = 0;
-    size_t offset, size, truncate;
+    size_t offset, size, truncate, len = 0;
 
     if (!event)
 	return;
