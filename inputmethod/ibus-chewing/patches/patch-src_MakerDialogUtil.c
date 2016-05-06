$NetBSD$

* use GLib function for "toupper".

--- src/MakerDialogUtil.c.orig	2015-12-01 13:44:17.000000000 +0000
+++ src/MakerDialogUtil.c
@@ -249,7 +249,7 @@ gchar *mkdg_str_dash_to_camel(const gcha
     int i;
     for (i = 0; i < strlen(argStr); i++) {
 	if (upper) {
-	    g_string_append_c(string, toupper(argStr[i]));
+	    g_string_append_c(string, g_ascii_toupper(argStr[i]));
 	    upper = FALSE;
 	} else {
 	    switch (argStr[i]) {
