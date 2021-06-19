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
@@ -72,3 +73,22 @@ unsigned long strlcat(char*, const char*
 }
 #endif
 #endif
+
+// tderesources/groupwise/soap
+#cmakedefine HAVE_STRRCHR
+#cmakedefine HAVE_STRTOD
+#cmakedefine HAVE_SSCANF
+#cmakedefine HAVE_STRTOL
+#cmakedefine HAVE_STRTOUL
+#cmakedefine HAVE_STRTOLL
+#cmakedefine HAVE_STRTOULL
+#cmakedefine HAVE_GETTIMEOFDAY
+#cmakedefine HAVE_SYS_TIMEB_H
+#cmakedefine HAVE_FTIME
+#cmakedefine HAVE_RAND_R
+#cmakedefine HAVE_GMTIME_R
+#cmakedefine HAVE_LOCALTIME_R
+#cmakedefine HAVE_TIMEGM
+#cmakedefine HAVE_WCTOMB
+#cmakedefine HAVE_MBTOWC
+#cmakedefine HAVE_ISNAN
