$NetBSD$

--- services/plugins/vix/vixToolsEnvVars.c.orig	2015-06-17 16:14:30.000000000 +0000
+++ services/plugins/vix/vixToolsEnvVars.c
@@ -94,7 +94,7 @@ struct VixToolsUserEnvironment {
 
 VixError
 VixToolsNewEnvIterator(void *userToken,                  // IN
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
                        char **envp,                      // IN
 #endif
                        VixToolsEnvIterator **envItr)     // OUT
