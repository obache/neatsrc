$NetBSD$

* Fix to use portable format

--- src/GSettingsBackend.c.orig	2016-04-14 09:40:07.000000000 +0000
+++ src/GSettingsBackend.c
@@ -65,22 +65,22 @@ gchar *mkdg_g_variant_to_string(GVariant
 	g_snprintf(result, MAKER_DIALOG_VALUE_LENGTH,
 		   g_variant_get_boolean(gVar) ? "1" : "0");
     } else if (g_variant_type_is_subtype_of(gVType, G_VARIANT_TYPE_UINT16)) {
-	g_snprintf(result, MAKER_DIALOG_VALUE_LENGTH, "%u",
+	g_snprintf(result, MAKER_DIALOG_VALUE_LENGTH, "%" G_GUINT16_FORMAT,
 		   g_variant_get_uint16(gVar));
     } else if (g_variant_type_is_subtype_of(gVType, G_VARIANT_TYPE_UINT32)) {
-	g_snprintf(result, MAKER_DIALOG_VALUE_LENGTH, "%u",
+	g_snprintf(result, MAKER_DIALOG_VALUE_LENGTH, "%" G_GUINT32_FORMAT,
 		   g_variant_get_uint32(gVar));
     } else if (g_variant_type_is_subtype_of(gVType, G_VARIANT_TYPE_UINT64)) {
-	g_snprintf(result, MAKER_DIALOG_VALUE_LENGTH, "%lu",
+	g_snprintf(result, MAKER_DIALOG_VALUE_LENGTH, "%" G_GUINT64_FORMAT,
 		   g_variant_get_uint64(gVar));
     } else if (g_variant_type_is_subtype_of(gVType, G_VARIANT_TYPE_INT16)) {
-	g_snprintf(result, MAKER_DIALOG_VALUE_LENGTH, "%d",
+	g_snprintf(result, MAKER_DIALOG_VALUE_LENGTH, "%" G_GINT16_FORMAT,
 		   g_variant_get_int16(gVar));
     } else if (g_variant_type_is_subtype_of(gVType, G_VARIANT_TYPE_INT32)) {
-	g_snprintf(result, MAKER_DIALOG_VALUE_LENGTH, "%d",
+	g_snprintf(result, MAKER_DIALOG_VALUE_LENGTH, "%" G_GINT32_FORMAT,
 		   g_variant_get_int32(gVar));
     } else if (g_variant_type_is_subtype_of(gVType, G_VARIANT_TYPE_INT64)) {
-	g_snprintf(result, MAKER_DIALOG_VALUE_LENGTH, "%ld",
+	g_snprintf(result, MAKER_DIALOG_VALUE_LENGTH, "%" G_GINT64_FORMAT,
 		   g_variant_get_int64(gVar));
     } else if (g_variant_type_is_subtype_of(gVType, G_VARIANT_TYPE_STRING)) {
 	g_snprintf(result, MAKER_DIALOG_VALUE_LENGTH, "%s",
