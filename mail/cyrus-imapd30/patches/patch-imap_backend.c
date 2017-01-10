$NetBSD$

* Set AI_V4MAPPED and AI_ADDRCONFIG only if supported

--- imap/backend.c.orig	2016-06-29 02:55:04.000000000 +0000
+++ imap/backend.c
@@ -877,7 +877,13 @@ static int backend_client_bind(const int
     hints.ai_family = dest->ai_family;
     hints.ai_socktype = dest->ai_socktype;
     hints.ai_protocol = dest->ai_protocol;
-    hints.ai_flags = AI_V4MAPPED | AI_ADDRCONFIG;
+    hints.ai_flags = 0;
+#if (AI_MASK + 0) & (AI_V4MAPPED + 0)
+    hints.ai_flags |= AI_V4MAPPED;
+#endif
+#if (AI_MASK+ 0) & (AI_ADDRCONFIG + 0)
+    hints.ai_flags |= AI_ADDRCONFIG;
+#endif
 
     r = getaddrinfo(client_bind_name, NULL, &hints, &res0);
     if (r && config_debug) {
