$NetBSD$

* Fix: return code of sodium_init() is not checked

--- src/curve_client.cpp.orig	2015-06-15 09:43:08.000000000 +0000
+++ src/curve_client.cpp
@@ -48,6 +48,7 @@ zmq::curve_client_t::curve_client_t (con
     cn_peer_nonce(1),
     sync()
 {
+    int rc;
     memcpy (public_key, options_.curve_public_key, crypto_box_PUBLICKEYBYTES);
     memcpy (secret_key, options_.curve_secret_key, crypto_box_SECRETKEYBYTES);
     memcpy (server_key, options_.curve_server_key, crypto_box_PUBLICKEYBYTES);
@@ -57,12 +58,12 @@ zmq::curve_client_t::curve_client_t (con
     unsigned char tmpbytes[4];
     randombytes(tmpbytes, 4);
 #else
-    // todo check return code
-    sodium_init();
+    rc = sodium_init();
+    zmq_assert (rc != -1);
 #endif
 
     //  Generate short-term key pair
-    const int rc = crypto_box_keypair (cn_public, cn_secret);
+    rc = crypto_box_keypair (cn_public, cn_secret);
     zmq_assert (rc == 0);
 }
 
