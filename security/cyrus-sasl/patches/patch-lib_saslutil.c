$NetBSD$

* Fix 64bit time_t on 32bit arch

--- lib/saslutil.c.orig	2018-10-09 14:36:41.000000000 +0000
+++ lib/saslutil.c
@@ -280,9 +280,9 @@ int sasl_mkchal(sasl_conn_t *conn,
   time(&now);
 
   if (hostflag && conn->serverFQDN)
-    snprintf(buf,maxlen, "<%lu.%lu@%s>", randnum, (unsigned long)now, conn->serverFQDN); /* don't care much about time 32bit overlap */
+    snprintf(buf,maxlen, "<%lu.%llu@%s>", randnum, (unsigned long long)now, conn->serverFQDN); /* don't care much about time 32bit overlap */
   else
-    snprintf(buf,maxlen, "<%lu.%lu>", randnum, (unsigned long)now);
+    snprintf(buf,maxlen, "<%lu.%llu>", randnum, (unsigned long long)now);
 
   return (int) strlen(buf);
 }
