$NetBSD$

* WTMPX filename is _PATH_WTMPX on NetBSD

--- src/wtmp-helper.c.orig	2014-11-04 03:46:00.000000000 +0000
+++ src/wtmp-helper.c
@@ -29,6 +29,12 @@
 
 #include <utmpx.h>
 
+#if !defined(WTMPX_FILENAME)
+#  if defined(_PATH_WTMPX)
+#    define WTMPX_FILENAME _PATH_WTMPX
+#  endif
+#endif
+
 typedef struct {
         guint64 frequency;
         gint64 time;
