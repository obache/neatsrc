$NetBSD$

* workaround for NetBSD openpam header

--- pam-ck-connector/pam-ck-connector.c.orig	2015-06-21 15:38:32.000000000 +0000
+++ pam-ck-connector/pam-ck-connector.c
@@ -52,6 +52,10 @@
 
 #define PAM_SM_SESSION
 
+#ifdef __NetBSD__
+#define NO_STATIC_MODULES
+#endif
+
 #include <security/pam_appl.h>
 #include <security/pam_modules.h>
 #ifdef HAVE_SECURITY_PAM_MODUTIL_H
