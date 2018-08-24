$NetBSD$

* NetBSD too

--- programs/dtpdmd/dtpdmd.c.orig	2018-07-06 18:05:20.000000000 +0000
+++ programs/dtpdmd/dtpdmd.c
@@ -172,7 +172,7 @@ static int generic_error_handler( edpy, 
  *
  *****************************************************************************/
 static void
-#if defined(__aix) || defined(__linux__)
+#if defined(__aix) || defined(__linux__) || defined(__NetBSD__)
 handle_SIGCLD(int sigNum)
 #else
 handle_SIGCLD(void)
