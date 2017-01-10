$NetBSD$

--- cunix.h.orig	2015-08-24 12:29:02.000000000 +0000
+++ cunix.h
@@ -40,7 +40,7 @@
 #define _T_TMPENV			"TEMP"			/* temporary 環境変数名 */
 #define _T_TMPENV2			"TMPDIR"		/* temporary 環境変数名 */
 #define _T_TMPDIR			"/tmp"			/* temporary directory */
-#define _T_SEARCH_DEFPATHS	"/usr/local/lib/today:/opt/local/lib/today:/usr/local/share/today:/opt/local/share/today:/usr/lib/today:/opt/lib/today:/usr/share/today:/opt/share/today:/usr/local/lib:/opt/local/lib:/usr/lib:/opt/lib"
+#define _T_SEARCH_DEFPATHS	"@PKG_SYSCONFDIR@"
 											/* default search path list */
 #define _T_HOMEENV			"HOME"			/* home 環境変数 */
 #define _T_PATHENV			"PATH"			/* path 環境変数名 */
@@ -50,7 +50,7 @@
 											/* path name of executed command */
 #define _T_EXECCMDPATH		"ExecCmdPath"	/* $ExecCmdPath => search_cmdpath */
 #define _T_OPENFLAG			(O_RDONLY)
-#if defined(i386)
+#if defined(__i386__) || defined(__amd64__) || defined(__x86_64__)
 #define _T_LITTLE_ENDIAN
 #define _T_LITTLE_ENDIAN_BITFIELD
 #else
@@ -60,7 +60,7 @@
 #define _T_OUTFILE_DEFAULT	"%c%y%m%d.today"
 #define _T_OUTFILE_TMPNAME	"%p.today"
 
-#if defined(linux)
+#if defined(unix)
 #define _T_ACCESS_ROK		R_OK
 #define _T_HAVE_STRTOK_R
 #define stricmp(a,b)		strcasecmp(a,b)
