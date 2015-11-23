$NetBSD$

* Fix to use portable functions

--- lib/ZDumpSession.c.orig	2013-10-28 04:21:47.000000000 +0000
+++ lib/ZDumpSession.c
@@ -42,7 +42,7 @@ ZDumpSession(char **buffer,
     for (key = Z_keys_head; key != NULL; key = key->next) {
 	num_keys++;
 	len += 4 + 4;  /* enctype, length */
-	len += key->keyblock->length;  /* contents */
+	len += Z_keylen(key->keyblock);  /* contents */
     }
 #endif
 
@@ -56,10 +56,10 @@ ZDumpSession(char **buffer,
 #ifdef HAVE_KRB5
     *((uint32_t *)ptr) = htonl(num_keys); ptr += 4;
     for (key = Z_keys_tail; key != NULL; key = key->prev) {
-	*((uint32_t*) ptr) = htonl(key->keyblock->enctype); ptr += 4;
-	*((uint32_t*) ptr) = htonl(key->keyblock->length); ptr += 4;
-	memcpy(ptr, key->keyblock->contents, key->keyblock->length);
-	ptr += key->keyblock->length;
+	*((uint32_t*) ptr) = htonl(Z_enctype(key->keyblock)); ptr += 4;
+	*((uint32_t*) ptr) = htonl(Z_keylen(key->keyblock)); ptr += 4;
+	memcpy(ptr, Z_keydata(key->keyblock), Z_keylen(key->keyblock));
+	ptr += Z_keylen(key->keyblock);
     }
 #endif
 
@@ -110,12 +110,30 @@ ZLoadSession(char *buffer, int len)
 	    free(key);
 	    return (EINVAL);
 	}
+#ifdef HAVE_KRB5_CREDS_KEYBLOCK_ENCTYPE
 	ret = krb5_init_keyblock(Z_krb5_ctx, enctype, keylength, &key->keyblock);
+#else
+	{
+	krb5_keyblock *tmp, tmp_ss;
+	tmp = &tmp_ss;
+
+	key->keyblock = NULL;
+	Z_enctype(tmp) = enctype;
+	Z_keylen(tmp) = keylength;
+	Z_keydata(tmp) = malloc(keylength);
+	if (!Z_keydata(tmp)) {
+		ret = ENOMEM;
+	} else {
+		ret =  krb5_copy_keyblock(Z_krb5_ctx, tmp, &key->keyblock);
+		free(Z_keydata(tmp));
+	}
+	}
+#endif
 	if (ret) {
 	    free(key);
 	    return ret;
 	}
-	memcpy((char *)key->keyblock->contents, buffer, keylength);
+	memcpy((char *)Z_keydata(key->keyblock), buffer, keylength);
 	buffer += keylength; len -= keylength;
 	/* Just set recent times. It means we might not be able to
 	   retire the keys, but that's fine. */
