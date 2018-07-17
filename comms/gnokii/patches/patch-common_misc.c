$NetBSD$

* fix ctype usage

--- common/misc.c.orig	2011-12-02 14:53:04.000000000 +0000
+++ common/misc.c
@@ -654,13 +654,13 @@ void gnokii_strfreev(char **str_array)
  */
 int gnokii_strcmpsep(const char *s1, const char *s2, char sep)
 {
-	while (isspace(*s2))
+	while (isspace((unsigned char)*s2))
 		s2++;
 	while (*s1 && *s1 == *s2) {
 		s1++;
 		s2++;
 	}
-	while (isspace(*s2))
+	while (isspace((unsigned char)*s2))
 		s2++;
 	if (!*s1 && *s2 == sep)
 		return 0;
