$NetBSD$

* Temporary disable build with spalsh backend

--- tdefile-plugins/dependencies/poppler-tqt/poppler-private.h.orig	2020-10-09 08:52:16.000000000 +0000
+++ tdefile-plugins/dependencies/poppler-tqt/poppler-private.h
@@ -29,6 +29,11 @@
 #include <Object.h>
 #include <PDFDoc.h>
 #include <FontInfo.h>
+
+#if defined(HAVE_SPLASH)
+# undef HAVE_SPLASH
+#endif
+
 #if defined(HAVE_SPLASH)
 #include <SplashOutputDev.h>
 #else
