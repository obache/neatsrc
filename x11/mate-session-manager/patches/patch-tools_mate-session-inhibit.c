$NetBSD$

* https://github.com/mate-desktop/mate-session-manager/issues/85

--- tools/mate-session-inhibit.c.orig	2015-06-11 19:13:45.000000000 +0000
+++ tools/mate-session-inhibit.c
@@ -24,6 +24,7 @@
 #include <unistd.h>
 #include <stdlib.h>
 #include <string.h>
+#include <locale.h>
 
 #include <glib.h>
 #include <glib/gi18n.h>
