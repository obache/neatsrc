$NetBSD$

* use a union for event parameter values rather than tyepecasting

--- imap/mboxevent.h.orig	2020-08-19 01:37:51.000000000 +0000
+++ imap/mboxevent.h
@@ -141,7 +141,11 @@ struct event_parameter {
     enum event_param id;
     const char *name;
     enum event_param_type type;
-    uint64_t value;
+    union {
+      char *s;
+      uint64_t u;
+      strarray_t *a;
+    }  value;
     int filled;
 };
 
