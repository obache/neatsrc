$NetBSD$

--- vgauth/lib/impersonateLinux.c.orig	2015-06-17 16:14:30.000000000 +0000
+++ vgauth/lib/impersonateLinux.c
@@ -29,7 +29,7 @@
 #define  _GNU_SOURCE
 #include <unistd.h>
 
-#if !defined(__FreeBSD__) && !defined(sun) && !defined(__APPLE__)
+#if !defined(__FreeBSD__) && !defined(sun) && !defined(__APPLE__) && !defined(__NetBSD__)
 #include <asm/param.h>
 #include <locale.h>
 #include <sys/stat.h>
@@ -122,7 +122,11 @@ VGAuthImpersonateImpl(VGAuthContext *ctx
    }
 
    // first change group
+#if defined(__APPLE__) || defined(__NetBSD__)
+   ret = setregid(ppw->pw_gid, ppw->pw_gid);
+#else
    ret = setresgid(ppw->pw_gid, ppw->pw_gid, root_gid);
+#endif
    if (ret < 0) {
       Warning("Failed to setresgid() for user %s (%d)\n", handle->userName, errno);
       return VGAUTH_E_FAIL;
@@ -133,7 +137,11 @@ VGAuthImpersonateImpl(VGAuthContext *ctx
       goto failure;
    }
    // now user
+#if defined(__APPLE__) || defined(__NetBSD__)
+   ret = setreuid(ppw->pw_uid, ppw->pw_uid);
+#else
    ret = setresuid(ppw->pw_uid, ppw->pw_uid, 0);
+#endif
    if (ret < 0) {
       Warning("Failed to setresuid() for user %s (%d)\n", handle->userName, errno);
       goto failure;
@@ -184,14 +192,22 @@ VGAuthEndImpersonationImpl(VGAuthContext
    }
 
    // first change back user
+#if defined(__APPLE__) || defined(__NetBSD__)
+   ret = setreuid(ppw->pw_uid, ppw->pw_uid);
+#else
    ret = setresuid(ppw->pw_uid, ppw->pw_uid, 0);
+#endif
    if (ret < 0) {
       Warning("Failed to setresuid() for root (%d)\n", errno);
       return VGAUTH_E_FAIL;
    }
 
    // now group
+#if defined(__APPLE__) || defined(__NetBSD__)
+   ret = setregid(ppw->pw_gid, ppw->pw_gid);
+#else
    ret = setresgid(ppw->pw_gid, ppw->pw_gid, ppw->pw_gid);
+#endif
    if (ret < 0) {
       Warning("Failed to setresgid() for root (%d)\n", errno);
       return VGAUTH_E_FAIL;
