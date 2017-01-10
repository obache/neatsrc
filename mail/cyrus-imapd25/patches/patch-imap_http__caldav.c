$NetBSD$

--- imap/http_caldav.c.orig	2015-05-08 03:49:52.000000000 +0000
+++ imap/http_caldav.c
@@ -3870,7 +3870,7 @@ static int propfind_timezone(const xmlCh
 {
     xmlNodePtr prop = (xmlNodePtr) rock;
     const char *data = NULL, *msg_base = NULL;
-    unsigned long datalen = 0;
+    size_t datalen = 0;
     int r = 0;
 
     if (propstat) {
