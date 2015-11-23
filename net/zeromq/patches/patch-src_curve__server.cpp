$NetBSD$

* Fix: return code of sodium_init() is not checked

--- src/curve_server.cpp.orig	2015-06-15 09:43:08.000000000 +0000
+++ src/curve_server.cpp
@@ -52,6 +52,7 @@ zmq::curve_server_t::curve_server_t (ses
     cn_peer_nonce(1),
     sync()
 {
+    int rc;
     //  Fetch our secret key from socket options
     memcpy (secret_key, options_.curve_secret_key, crypto_box_SECRETKEYBYTES);
     scoped_lock_t lock (sync);
@@ -60,12 +61,12 @@ zmq::curve_server_t::curve_server_t (ses
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
 
