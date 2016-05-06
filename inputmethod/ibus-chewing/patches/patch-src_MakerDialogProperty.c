$NetBSD$

* Fix to return NULL as FALSE

--- src/MakerDialogProperty.c.orig	2016-04-20 14:58:18.000000000 +0000
+++ src/MakerDialogProperty.c
@@ -113,15 +113,15 @@ GValue *property_context_read(PropertyCo
 gboolean property_context_write(PropertyContext * ctx, gpointer userData)
 {
     if (ctx == NULL) {
-	return NULL;
+	return FALSE;
     }
     mkdg_log(DEBUG, "property_context_read(%s,-)", ctx->spec->key);
     if (mkdg_has_flag
 	(ctx->spec->propertyFlags, MKDG_PROPERTY_FLAG_NO_BACKEND)) {
-	return NULL;
+	return FALSE;
     }
     if (ctx->backend == NULL) {
-	return NULL;
+	return FALSE;
     }
     return ctx->backend->writeFunc(ctx->backend, &(ctx->value),
 				   ctx->spec->subSection, ctx->spec->key,
