$NetBSD$

* avoid dereferencing unit32_t on unaligned address
  (from upstream master)

--- src/socket_base.cpp.orig	2015-12-18 08:21:09.000000000 +0000
+++ src/socket_base.cpp
@@ -1323,8 +1323,11 @@ void zmq::socket_base_t::monitor_event (
         zmq_msg_t msg;
         zmq_msg_init_size (&msg, 6);
         uint8_t *data = (uint8_t *) zmq_msg_data (&msg);
-        *(uint16_t *) (data + 0) = (uint16_t) event_;
-        *(uint32_t *) (data + 2) = (uint32_t) value_;
+        //  Avoid dereferencing unit32_t on unaligned address
+        uint16_t event = (uint16_t) event_;
+        uint32_t value = (uint32_t) value_;
+        memcpy (data + 0, &event, sizeof(event));
+        memcpy (data + 2, &value, sizeof(value));
         zmq_sendmsg (monitor_socket, &msg, ZMQ_SNDMORE);
 
         //  Send address in second frame
