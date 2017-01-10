$NetBSD$

--- version.c.orig	2015-08-24 12:42:41.000000000 +0000
+++ version.c
@@ -43,11 +43,11 @@ const char	UseLanguage[] =
 #elif defined(_T_WIN32CONSOLE) && (__BORLANDC__ == 0x551)
 	"Borland C++ Version 5.5.1";
 #else
-#error UseLanguage not define!!
+	"@CC_VERSION@";
 #endif
 
 #ifdef TRANS
-const char	Modify[] = "Modified for 機種名/OS名 by 移植者名";
+const char	Modify[] = "Modified for @MACHINE_PLATFORM@ by @LOGNAME@";
 #endif
 
 #endif /* !_T_WINDOWS */
