$NetBSD$

--- programs/dtpdmd/dtpdmd.c.orig	2015-05-09 23:09:11.000000000 +0000
+++ programs/dtpdmd/dtpdmd.c
@@ -170,7 +170,7 @@ static int generic_error_handler( edpy, 
  *
  *****************************************************************************/
 static void
-#if defined(__aix) || defined(linux)
+#if defined(__aix) || defined(linux) || defined(__NetBSD__)
 handle_SIGCLD(int sigNum)
 #else
 handle_SIGCLD(void)
