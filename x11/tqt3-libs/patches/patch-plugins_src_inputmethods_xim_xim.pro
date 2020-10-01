$NetBSD$

* disable debug

--- plugins/src/inputmethods/xim/xim.pro.orig	2018-06-03 22:24:59.000000000 +0000
+++ plugins/src/inputmethods/xim/xim.pro
@@ -3,7 +3,7 @@ TARGET = qxim
 DESTDIR  = ../../../inputmethods
 
 INCLUDEPATH += .
-CONFIG      += qt warn_on debug plugin
+CONFIG      += qt warn_on plugin
 target.path += $$plugins.path/inputmethods
 INSTALLS    += target
 DEFINES     += QT_NO_XINERAMA
