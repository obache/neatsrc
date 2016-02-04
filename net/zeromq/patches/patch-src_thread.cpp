$NetBSD$

* Use spec macro to detect posix thread priority scheduling

--- src/thread.cpp.orig	2015-11-04 08:55:13.000000000 +0000
+++ src/thread.cpp
@@ -114,7 +114,7 @@ void zmq::thread_t::stop ()
 
 void zmq::thread_t::setSchedulingParameters(int priority_, int schedulingPolicy_)
 {
-#if !defined ZMQ_HAVE_ZOS
+#if _POSIX_THREAD_PRIORITY_SCHEDULING > 0
     int policy = 0;
     struct sched_param param;
 
