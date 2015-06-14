$NetBSD$

* this decimal constant is unsigned only in ISO C90

--- imap/sync_support.c.orig	2015-05-08 03:49:52.000000000 +0000
+++ imap/sync_support.c
@@ -672,7 +672,7 @@ void sync_decode_quota_limits(/*const*/ 
 
     /* For backwards compatibility */
     if (dlist_getnum32(kl, "LIMIT", &limit)) {
-	if (limit == 4294967295)
+	if (limit == 4294967295U)
 	    limits[QUOTA_STORAGE] = -1;
 	else
 	    limits[QUOTA_STORAGE] = limit;
