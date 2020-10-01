$NetBSD$

--- tdespell2/plugins/ispell/ispell_checker.cpp.orig	2020-04-10 23:08:30.000000000 +0000
+++ tdespell2/plugins/ispell/ispell_checker.cpp
@@ -55,6 +55,9 @@ typedef struct str_ispell_map
 } IspellMap;
 
 static const char *ispell_dirs [] = {
+#ifdef ISPELL_LIBDIR
+	ISPELL_LIBDIR,
+#else
 	"/usr/" SYSTEM_LIBDIR "/ispell",
 	"/usr/lib/ispell",
 	"/usr/local/" SYSTEM_LIBDIR "/ispell",
@@ -62,6 +65,7 @@ static const char *ispell_dirs [] = {
 	"/usr/local/share/ispell",
 	"/usr/share/ispell",
 	"/usr/pkg/lib",
+#endif
 	0
 };
 static const IspellMap ispell_map [] = {
