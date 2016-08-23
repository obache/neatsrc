$NetBSD$

* this decimal constant is unsigned only in ISO C90

--- imap/sync_support.c.orig	2016-07-22 01:55:57.000000000 +0000
+++ imap/sync_support.c
@@ -57,6 +57,7 @@
 #include <errno.h>
 #include <dirent.h>
 #include <utime.h>
+#include <limits.h>
 
 #include "global.h"
 #include "mboxlist.h"
@@ -672,7 +673,7 @@ void sync_decode_quota_limits(/*const*/ 
 
     /* For backwards compatibility */
     if (dlist_getnum32(kl, "LIMIT", &limit)) {
-	if (limit == 4294967295)
+	if (limit == UINT_MAX)
 	    limits[QUOTA_STORAGE] = -1;
 	else
 	    limits[QUOTA_STORAGE] = limit;
