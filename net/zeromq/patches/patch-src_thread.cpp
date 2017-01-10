$NetBSD$

* Use spec macro to detect posix thread priority scheduling

--- src/thread.cpp.orig	2015-11-04 08:55:13.000000000 +0000
+++ src/thread.cpp
@@ -114,10 +114,15 @@ void zmq::thread_t::stop ()
 
 void zmq::thread_t::setSchedulingParameters(int priority_, int schedulingPolicy_)
 {
-#if !defined ZMQ_HAVE_ZOS
+#if defined _POSIX_THREAD_PRIORITY_SCHEDULING && _POSIX_THREAD_PRIORITY_SCHEDULING >= 0
     int policy = 0;
     struct sched_param param;
 
+#if _POSIX_THREAD_PRIORITY_SCHEDULING == 0 && defined _SC_THREAD_PRIORITY_SCHEDULING
+    if (sysconf(_SC_THREAD_PRIORITY_SCHEDULING) < 0) {
+        return;
+    }
+#endif
     int rc = pthread_getschedparam(descriptor, &policy, &param);
     posix_assert (rc);
 
