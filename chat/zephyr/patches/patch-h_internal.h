$NetBSD$

* move compat function from server

--- h/internal.h.orig	2013-10-28 04:21:47.000000000 +0000
+++ h/internal.h
@@ -83,6 +83,8 @@ extern int __Zephyr_server;	/* 0 if norm
 #ifdef HAVE_KRB5
 extern krb5_context Z_krb5_ctx;
 Code_t Z_krb5_lookup_cksumtype(krb5_enctype, krb5_cksumtype *);
+krb5_error_code Z_krb5_init_keyblock(krb5_context, krb5_enctype, size_t,
+        krb5_keyblock **);
 
 struct _Z_SessionKey {
     struct _Z_SessionKey    *next;
