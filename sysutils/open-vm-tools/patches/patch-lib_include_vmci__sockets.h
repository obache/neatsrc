$NetBSD$

--- lib/include/vmci_sockets.h.orig	2015-06-17 16:14:30.000000000 +0000
+++ lib/include/vmci_sockets.h
@@ -39,7 +39,7 @@
 #  if defined(__APPLE__)
 #    include <sys/socket.h>
 #    include <string.h>
-#  elif defined(__FreeBSD__)
+#  elif defined(__FreeBSD__) || defined(__NetBSD__)
 #     include <sys/socket.h>
 #  endif // __FreeBSD__
 #endif // linux && !VMKERNEL
@@ -383,7 +383,7 @@
  */
 
 struct sockaddr_vm {
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
    unsigned char svm_len;
 #endif // __APPLE__ || __FreeBSD__
 
@@ -837,7 +837,7 @@ struct uuid_2_cid {
       return io.u2c_context_id;
    }
 #  endif // __KERNEL__
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
    /*
     * No FreeBSD support yet, but it might appear in the future. Just define
     * some stubs that return errors - that way a client doesn't have to ifdef
