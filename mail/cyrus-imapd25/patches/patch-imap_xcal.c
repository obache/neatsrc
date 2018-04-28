$NetBSD$

* libical >= 3.0 API

--- imap/xcal.c.orig	2017-05-09 00:40:13.000000000 +0000
+++ imap/xcal.c
@@ -114,7 +114,7 @@ const char *icaltime_as_iso_string(const
     const char *fmt;
 
     if (tt.is_date) fmt = "%04d-%02d-%02d";
-    else if (tt.is_utc) fmt = "%04d-%02d-%02dT%02d:%02d:%02dZ";
+    else if (icaltime_is_utc(tt)) fmt = "%04d-%02d-%02dT%02d:%02d:%02dZ";
     else fmt = "%04d-%02d-%02dT%02d:%02d:%02d";
 
     snprintf(str, sizeof(str), fmt, tt.year, tt.month, tt.day,
