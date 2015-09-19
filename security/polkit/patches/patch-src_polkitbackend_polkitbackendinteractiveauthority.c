$NetBSD$

* getnetgrent(3) is in netgroup.h on NetBSD

--- src/polkitbackend/polkitbackendinteractiveauthority.c.orig	2015-06-19 20:39:58.000000000 +0000
+++ src/polkitbackend/polkitbackendinteractiveauthority.c
@@ -23,7 +23,11 @@
 #include <errno.h>
 #include <pwd.h>
 #include <grp.h>
+#if defined(__NetBSD__)
+#include <netgroup.h>
+#else
 #include <netdb.h>
+#endif
 #include <string.h>
 #include <glib/gstdio.h>
 #include <locale.h>
