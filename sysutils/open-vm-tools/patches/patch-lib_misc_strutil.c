$NetBSD$

--- lib/misc/strutil.c.orig	2015-06-17 16:14:30.000000000 +0000
+++ lib/misc/strutil.c
@@ -1213,7 +1213,7 @@ StrUtil_TrimWhitespace(const char *str) 
    size_t len;
 
    /* Skip leading whitespace. */
-   while (*cur && isspace(*cur)) {
+   while (*cur && isspace((int)*cur)) {
       cur++;
    }
 
@@ -1227,7 +1227,7 @@ StrUtil_TrimWhitespace(const char *str) 
    }
 
    cur = res + len - 1;
-   while (cur > res && isspace(*cur)) {
+   while (cur > res && isspace((int)*cur)) {
       cur--;
    }
 
