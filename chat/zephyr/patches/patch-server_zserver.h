$NetBSD$

* move compat function to lib

--- server/zserver.h.orig	2013-10-28 04:21:47.000000000 +0000
+++ server/zserver.h
@@ -37,8 +37,6 @@
 extern krb5_keyblock *__Zephyr_keyblock;
 #define ZGetSession() (__Zephyr_keyblock)
 void ZSetSession(krb5_keyblock *keyblock);
-krb5_error_code Z_krb5_init_keyblock(krb5_context, krb5_enctype, size_t,
-        krb5_keyblock **);
 #endif
 
 #ifdef HAVE_KRB4
