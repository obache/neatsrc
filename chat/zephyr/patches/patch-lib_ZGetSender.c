$NetBSD$

* Fix to use the function conditionally

--- lib/ZGetSender.c.orig	2013-10-28 04:21:47.000000000 +0000
+++ lib/ZGetSender.c
@@ -46,7 +46,11 @@ ZGetSender(void)
       if (!result) {
 	krb5_unparse_name(Z_krb5_ctx, principal, &prname);
 	sender = strdup(prname);
+#ifdef HAVE_KRB5_UNPARSE_NAME
 	krb5_free_unparsed_name(Z_krb5_ctx, prname);
+#else
+	free(prname);
+#endif
 	krb5_free_principal(Z_krb5_ctx, principal);
 	return sender;
       }
