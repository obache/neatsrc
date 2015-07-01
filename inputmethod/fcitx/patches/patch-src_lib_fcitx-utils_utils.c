$NetBSD$

* NetBSD support

--- src/lib/fcitx-utils/utils.c.orig	2015-04-17 16:43:29.000000000 +0000
+++ src/lib/fcitx-utils/utils.c
@@ -507,6 +507,10 @@ char* fcitx_utils_get_process_name()
     /* } while(0); */
     /* return strdup(""); */
 #elif defined(LIBKVM_FOUND)
+#ifdef __NetBSD__
+#define ki_pid kp_proc.p_pid
+#define ki_comm kp_proc.p_comm
+#endif
     kvm_t *vm = kvm_open(0, "/dev/null", 0, O_RDONLY, NULL);
     if (vm == 0)
         return strdup("");
