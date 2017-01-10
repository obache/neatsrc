$NetBSD: patch-handwriting_zinnia__handwriting.cc,v 1.3 2016/05/16 11:51:49 ryoon Exp $

* Not confirmed yet.

--- handwriting/zinnia_handwriting.cc.orig	2016-01-10 19:41:41.000000000 +0000
+++ handwriting/zinnia_handwriting.cc
@@ -57,9 +57,9 @@ string ZinniaHandwriting::GetModelFileNa
   // used.  See also gui.gyp:hand_writing_mac.
   const char kModelFile[] = "handwriting-light-ja.model";
   return FileUtil::JoinPath(MacUtil::GetResourcesDirectory(), kModelFile);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_NETBSD)
   const char kModelFile[] =
-      "/usr/share/tegaki/models/zinnia/handwriting-ja.model";
+      "@PREFIX@/share/tegaki/models/zinnia/handwriting-ja.model";
   return kModelFile;
 #else
   const char kModelFile[] = "handwriting-ja.model";
