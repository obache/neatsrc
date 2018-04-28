$NetBSD$

* libical >= 3.0 API
* fix type mismatch

--- imap/http_caldav.c.orig	2017-05-09 00:40:13.000000000 +0000
+++ imap/http_caldav.c
@@ -2023,7 +2023,7 @@ static struct icaltimetype icaltime_from
 	goto fail;
     }
 
-    tt.is_utc = 1;
+    icaltime_set_timezone(&tt, icaltimezone_get_utc_timezone());
     return tt;
 
   fail:
@@ -3894,7 +3894,7 @@ static int propfind_timezone(const xmlCh
 {
     xmlNodePtr prop = (xmlNodePtr) rock;
     const char *data = NULL, *msg_base = NULL;
-    unsigned long datalen = 0;
+    size_t datalen = 0;
     int r = 0;
 
     if (propstat) {
