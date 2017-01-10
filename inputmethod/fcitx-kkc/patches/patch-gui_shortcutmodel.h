$NetBSD$

* prevent to depend on C++11

--- gui/shortcutmodel.h.orig	2015-05-18 15:47:33.000000000 +0000
+++ gui/shortcutmodel.h
@@ -36,8 +36,14 @@ public:
     }
 
     ShortcutEntry(const ShortcutEntry& other) :
-        ShortcutEntry(other.m_command, KKC_KEY_EVENT(g_object_ref(other.m_event)), other.m_label, other.m_mode)
+        m_command(other.m_command),
+	m_event(KKC_KEY_EVENT(g_object_ref(other.m_event))),
+	m_label(other.m_label),
+	m_mode(other.m_mode)
     {
+        gchar* keystr = kkc_key_event_to_string(m_event);
+        m_keyString = QString::fromUtf8(keystr);
+        g_free(keystr);
     }
 
     ~ShortcutEntry() {
