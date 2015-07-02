$NetBSD$

* NetBSD and OpeBSD support

--- src/lib/fcitx-utils/utils.c.orig	2015-04-17 16:43:29.000000000 +0000
+++ src/lib/fcitx-utils/utils.c
@@ -507,7 +507,11 @@ char* fcitx_utils_get_process_name()
     /* } while(0); */
     /* return strdup(""); */
 #elif defined(LIBKVM_FOUND)
+#if defined(__NetBSD__) || defined(__OpenBSD__)
+    kvm_t *vm = kvm_open(NULL, NULL, NULL, KVM_NO_FILES, NULL);
+#else
     kvm_t *vm = kvm_open(0, "/dev/null", 0, O_RDONLY, NULL);
+#endif
     if (vm == 0)
         return strdup("");
 
@@ -515,16 +519,28 @@ char* fcitx_utils_get_process_name()
     do {
         int cnt;
         int mypid = getpid();
+#ifdef __NetBSD__
+        struct kinfo_proc2 * kp = kvm_getproc2(vm, KERN_PROC_PID, mypid, sizeof(struct kinfo_proc2), &cnt);
+#else
         struct kinfo_proc * kp = kvm_getprocs(vm, KERN_PROC_PID, mypid, &cnt);
+#endif
         if ((cnt != 1) || (kp == 0)) {
             break;
         }
         int i;
         for (i = 0; i < cnt; i++)
+#if defined(__NetBSD__) || defined(__OpenBSD__)
+            if (kp->p_pid == mypid)
+#else
             if (kp->ki_pid == mypid)
+#endif
                 break;
         if (i != cnt)
+#if defined(__NetBSD__) || defined(__OpenBSD__)
+            result = strdup(kp->p_comm);
+#else
             result = strdup(kp->ki_comm);
+#endif
     } while (0);
     kvm_close(vm);
     if (result == NULL)
