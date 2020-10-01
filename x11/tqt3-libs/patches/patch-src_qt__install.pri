$NetBSD$

--- src/qt_install.pri.orig	2016-09-11 06:09:05.000000000 +0000
+++ src/qt_install.pri
@@ -13,7 +13,7 @@ INSTALLS += headers headers_p
 #docs
 htmldocs.files = ../doc/html/*
 htmldocs.path = $$docs.path/html
-INSTALLS += htmldocs
+#INSTALLS += htmldocs
 
 #translations
 translations.files = ../translations/*.qm
