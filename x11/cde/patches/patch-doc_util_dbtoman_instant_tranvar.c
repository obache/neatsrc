$NetBSD$

* missing forward reference

--- doc/util/dbtoman/instant/tranvar.c.orig	2019-10-12 21:43:45.000000000 +0000
+++ doc/util/dbtoman/instant/tranvar.c
@@ -97,6 +97,8 @@ static char	*each_C = 0;	/* last seen _e
 void	ChaseIDRefs(Element_t *, char *, char *, FILE *);
 void	Find(Element_t *, int, char **, FILE *);
 void	GetIDREFnames();
+void	ExpandVariables(char *, char *, Element_t *);
+void	CALStable(Element_t *, FILE *, char **, int);
 
 /* ______________________________________________________________________ */
 /*  Handle "special" variable - read file, run command, do action, etc.
