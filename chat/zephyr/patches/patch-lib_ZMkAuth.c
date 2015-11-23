$NetBSD$

* Fix to use portable functions

--- lib/ZMkAuth.c.orig	2013-10-28 04:21:47.000000000 +0000
+++ lib/ZMkAuth.c
@@ -126,10 +126,10 @@ Z_MakeAuthenticationSaveKey(register ZNo
     keyblock = Z_credskey(creds);
 
     if (Z_keys_head &&
-	Z_keys_head->keyblock->enctype == keyblock->enctype &&
-	Z_keys_head->keyblock->length == keyblock->length &&
-	memcmp(Z_keys_head->keyblock->contents, keyblock->contents,
-	       keyblock->length) == 0) {
+	Z_enctype(Z_keys_head->keyblock) == Z_enctype(keyblock) &&
+	Z_keylen(Z_keys_head->keyblock) == Z_keylen(keyblock) &&
+	memcmp(Z_keydata(Z_keys_head->keyblock), Z_keydata(keyblock),
+	       Z_keylen(keyblock)) == 0) {
 	/*
 	 * Optimization: if the key hasn't changed, replace the current entry,
 	 * rather than make a new one.
