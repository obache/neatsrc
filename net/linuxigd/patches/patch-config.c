$NetBSD$

* for missing strnlen(3)

--- config.c.orig	2006-11-12 15:38:46.000000000 +0000
+++ config.c
@@ -7,6 +7,25 @@
 
 #define NMATCH 3
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+
+#if __NetBSD_Version__ < 600000000
+
+static size_t strnlen(const char* s, size_t maxlen) {
+    int len;
+
+    for(len = 0; len < maxlen; len++) {
+	if(s[len] == '\0') {
+	    len++;
+	    break;
+	}
+    }
+    return len;
+}
+#endif
+#endif
+
 int getConfigOptionArgument(char var[],int varlen, char line[], regmatch_t *submatch) 
 {
     /* bound buffer operations to varlen - 1 */
