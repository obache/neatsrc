$NetBSD$

* add pkg system X11 paths

--- kxkb/x11helper.cpp.orig	2015-09-23 03:07:44.000000000 +0000
+++ kxkb/x11helper.cpp
@@ -23,6 +23,9 @@
 static const char* X11DirList[] =
     {
         XLIBDIR,
+	"@LOCALBASE@/share/X11/",
+	"@X11BASE@/share/X11/",
+	"@PKG_SYSCONFBASE@/X11/",
         "/usr/share/X11/",
         "/etc/X11/",
         "/usr/local/share/X11/",
