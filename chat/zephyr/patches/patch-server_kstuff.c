$NetBSD$

* move compat function to lib

--- server/kstuff.c.orig	2013-10-28 04:21:47.000000000 +0000
+++ server/kstuff.c
@@ -701,33 +701,6 @@ static ZChecksum_t compute_rlm_checksum(
 
     return checksum;
 }
-#endif
-
-#ifdef HAVE_KRB5
-krb5_error_code
-Z_krb5_init_keyblock(krb5_context context,
-	krb5_enctype type,
-	size_t size,
-	krb5_keyblock **key)
-{
-#ifdef HAVE_KRB5_CREDS_KEYBLOCK_ENCTYPE
-	return krb5_init_keyblock(context, type, size, key);
-#else
-	krb5_error_code ret;
-	krb5_keyblock *tmp, tmp_ss;
-	tmp = &tmp_ss;
-
-	*key = NULL;
-	Z_enctype(tmp) = type;
-	Z_keylen(tmp) = size;
-	Z_keydata(tmp) = malloc(size);
-	if (!Z_keydata(tmp))
-		return ENOMEM;
-	ret =  krb5_copy_keyblock(context, tmp, key);
-	free(Z_keydata(tmp));
-	return ret;
-#endif
-}
 
 void
 ZSetSession(krb5_keyblock *keyblock) {
