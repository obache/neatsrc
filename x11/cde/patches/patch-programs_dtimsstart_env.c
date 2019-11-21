$NetBSD$

* declare used function

--- programs/dtimsstart/env.c.orig	2019-10-12 21:43:45.000000000 +0000
+++ programs/dtimsstart/env.c
@@ -32,6 +32,7 @@ typedef	enum {
     C_Shell	/* C shell */
 } ShellType;
 
+extern int find_CDE_locale_name(void);
 
     /* local func */
 static int	shell_type(/* shell */);
