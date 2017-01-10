$NetBSD$

* remove redundant scope

--- src/scim_sinhala_imengine.cpp.orig	2008-05-28 11:32:29.000000000 +0000
+++ src/scim_sinhala_imengine.cpp
@@ -233,7 +233,7 @@ void SinhalaInstance::trigger_property(c
 
 void SinhalaInstance::backspace()
 {
-	KeyEvent e = scim::KeyEvent::KeyEvent(SCIM_KEY_BackSpace, 0);
+	KeyEvent e = scim::KeyEvent(SCIM_KEY_BackSpace, 0);
 	forward_key_event(e);
 }
 
