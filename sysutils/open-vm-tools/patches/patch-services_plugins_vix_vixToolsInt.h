$NetBSD$

--- services/plugins/vix/vixToolsInt.h.orig	2015-06-17 16:14:30.000000000 +0000
+++ services/plugins/vix/vixToolsInt.h
@@ -111,7 +111,7 @@ void VixToolsUnimpersonateUser(void *use
 void VixToolsLogoutUser(void *userToken);
 
 VixError VixToolsNewEnvIterator(void *userToken,
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
                                 char **envp,
 #endif
                                 VixToolsEnvIterator **envItr);
