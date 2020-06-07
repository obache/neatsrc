$NetBSD$

* move compat function from server

--- lib/Zinternal.c.orig	2013-10-28 04:21:47.000000000 +0000
+++ lib/Zinternal.c
@@ -99,6 +99,31 @@ Z_krb5_lookup_cksumtype(krb5_enctype e,
   }
   return KRB5_PROG_ETYPE_NOSUPP;
 }
+
+krb5_error_code
+Z_krb5_init_keyblock(krb5_context context,
+	krb5_enctype type,
+	size_t size,
+	krb5_keyblock **key)
+{
+#ifdef HAVE_KRB5_CREDS_KEYBLOCK_ENCTYPE
+	return krb5_init_keyblock(context, type, size, key);
+#else
+	krb5_error_code ret;
+	krb5_keyblock *tmp, tmp_ss;
+	tmp = &tmp_ss;
+
+	*key = NULL;
+	Z_enctype(tmp) = type;
+	Z_keylen(tmp) = size;
+	Z_keydata(tmp) = malloc(size);
+	if (!Z_keydata(tmp))
+		return ENOMEM;
+	ret =  krb5_copy_keyblock(context, tmp, key);
+	free(Z_keydata(tmp));
+	return ret;
+#endif
+}
 #endif /* HAVE_KRB5 */
 
 char __Zephyr_realm[REALM_SZ];
