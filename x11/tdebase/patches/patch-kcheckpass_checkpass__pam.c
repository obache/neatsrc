$NetBSD$

--- kcheckpass/checkpass_pam.c.orig	2016-11-07 05:13:18.000000000 +0000
+++ kcheckpass/checkpass_pam.c
@@ -150,6 +150,8 @@ AuthReturn Authenticate(const char *call
     sprintf(pservb, "%.31s-%.31s", caller, method);
     pam_service = pservb;
   }
+  if (strchr(pam_service, '/'))	/* service shouldn't be a path */
+    return AuthError;
   pam_error = pam_start(pam_service, user, &PAM_conversation, &pamh);
   if (pam_error != PAM_SUCCESS)
     return AuthError;
