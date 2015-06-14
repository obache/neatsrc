$NetBSD$

--- imap/http_rss.c.orig	2015-05-08 03:49:52.000000000 +0000
+++ imap/http_rss.c
@@ -479,7 +479,7 @@ static int list_feeds(struct transaction
 {
     const char *template_file = config_getstring(IMAPOPT_RSS_FEEDLIST_TEMPLATE);
     const char *var = NULL, *template = NULL, *prefix, *suffix;
-    unsigned long template_len = 0, prefix_len, suffix_len;
+    size_t template_len = 0, prefix_len, suffix_len;
     size_t varlen = strlen(FEEDLIST_VAR);
     int fd = -1;
     struct message_guid guid;
