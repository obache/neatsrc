$NetBSD$

* fix missing gnokii.h check

--- config.h.cmake.orig	2021-04-10 10:45:46.000000000 +0000
+++ config.h.cmake
@@ -43,6 +43,7 @@
 #cmakedefine STD_NAMESPACE_PREFIX @STD_NAMESPACE_PREFIX@
 
 // kaddressbook
+#cmakedefine HAVE_GNOKII_H 1
 #cmakedefine TDEPIM_NEW_DISTRLISTS 1
 
 // karm
