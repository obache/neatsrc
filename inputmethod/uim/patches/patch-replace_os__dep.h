$NetBSD$

* strtonum(3) is an OpenBSD extension on NetBSD-8

--- replace/os_dep.h.orig	2017-08-14 00:07:27.000000000 +0000
+++ replace/os_dep.h
@@ -135,6 +135,9 @@ long long strtoll(const char *, char **,
 #ifndef HAVE_STRTONUM
 #define strtonum	uim_internal_strtonum
 long long strtonum(const char *numstr, long long minval, long long maxval, const char **errstrp);
+#elif defined(__NetBSD__)
+#define _OPENBSD_SOURCE
+#include <stdlib.h>
 #endif
 
 #ifdef HAVE_POLL_H
