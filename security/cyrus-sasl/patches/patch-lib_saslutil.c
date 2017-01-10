$NetBSD$

* Fix 64bit time_t on 32bit arch

--- lib/saslutil.c.orig	2012-10-12 14:05:48.000000000 +0000
+++ lib/saslutil.c
@@ -288,9 +288,9 @@ int sasl_mkchal(sasl_conn_t *conn,
   time(&now);
 
   if (hostflag && conn->serverFQDN)
-    snprintf(buf,maxlen, "<%lu.%lu@%s>", randnum, now, conn->serverFQDN);
+    snprintf(buf,maxlen, "<%lu.%llu@%s>", randnum, (unsigned long long)now, conn->serverFQDN);
   else
-    snprintf(buf,maxlen, "<%lu.%lu>", randnum, now);
+    snprintf(buf,maxlen, "<%lu.%llu>", randnum, (unsigned long long)now);
 
   return (int) strlen(buf);
 }
