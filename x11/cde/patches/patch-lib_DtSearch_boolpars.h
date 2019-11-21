$NetBSD$

* missing declare

--- lib/DtSearch/boolpars.h.orig	2019-11-16 02:06:11.000000000 +0000
+++ lib/DtSearch/boolpars.h
@@ -132,6 +132,8 @@ extern TRUTHTAB	*boolyac_COLLOC (TRUTHTA
 extern TRUTHTAB	*boolyac_NOT (TRUTHTAB *tt1);
 extern TRUTHTAB	*boolyac_OR (TRUTHTAB *tt1, TRUTHTAB *tt2);
 extern TRUTHTAB *copy_final_truthtab (TRUTHTAB *tt);
+extern int	yylex (void);
+extern void	yyerror (char *msg);
 
 /******************** BOOLPARS.H *********************/
 #endif /* _boolpars_h */
