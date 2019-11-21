$NetBSD$

* missing forward reference

--- doc/util/dbtoman/instant/traninit.c.orig	2019-10-12 21:43:45.000000000 +0000
+++ doc/util/dbtoman/instant/traninit.c
@@ -100,6 +100,7 @@
 
 /* forward references */
 void	RememberTransSpec(Trans_t *, int);
+void	ExpandVariables(char *, char *, Element_t *);
 
 /* ______________________________________________________________________ */
 /*  Read the translation specs from the input file, storing in memory.
