$NetBSD$

* for missing LC_IDENTIFICATION support

--- liblightdm-gobject/language.c.orig	2015-10-28 02:06:57.000000000 +0000
+++ liblightdm-gobject/language.c
@@ -224,6 +224,7 @@ lightdm_language_get_name (LightDMLangua
 
     if (!priv->name)
     {
+#ifdef LC_IDENTIFICATION
         gchar *locale = get_locale_name (priv->code);
         if (locale)
         {
@@ -237,6 +238,7 @@ lightdm_language_get_name (LightDMLangua
 
             setlocale (LC_ALL, current);
         }
+#endif
         if (!priv->name)
         {
             gchar **tokens = g_strsplit_set (priv->code, "_.@", 2);
@@ -267,6 +269,7 @@ lightdm_language_get_territory (LightDML
 
     if (!priv->territory && strchr (priv->code, '_'))
     {
+#ifdef LC_IDENTIFICATION
         gchar *locale = get_locale_name (priv->code);
         if (locale)
         {
@@ -280,6 +283,7 @@ lightdm_language_get_territory (LightDML
 
             setlocale (LC_ALL, current);
         }
+#endif
         if (!priv->territory)
         {
             gchar **tokens = g_strsplit_set (priv->code, "_.@", 3);
