$NetBSD$

* fix ctype usage

--- common/gsm-common.c.orig	2011-12-02 14:53:04.000000000 +0000
+++ common/gsm-common.c
@@ -664,8 +664,8 @@ GNOKII_API void gn_number_sanitize(char 
 	iter = e = number;
 	while (*iter && *e && (e - number < maxlen)) {
 		*iter = *e;
-		if (isspace(*iter)) {
-			while (*e && isspace(*e) && (e - number < maxlen)) {
+		if (isspace((unsigned char)*iter)) {
+			while (*e && isspace((unsigned char)*e) && (e - number < maxlen)) {
 				e++;
 			}
 		}
