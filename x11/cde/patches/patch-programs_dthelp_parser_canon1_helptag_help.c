$NetBSD$

* exactly delcare as int

--- programs/dthelp/parser/canon1/helptag/help.c.orig	2019-10-12 21:43:45.000000000 +0000
+++ programs/dthelp/parser/canon1/helptag/help.c
@@ -2177,7 +2177,7 @@ return(newstring);
 
 int NextId(void)
 {
-static id = 0;
+static int id = 0;
 
 return ++id;
 }
@@ -2713,7 +2713,7 @@ M_WCHAR *CycleEnt(LOGICAL init,
 {
 static M_TRIE *current ;
 static M_TRIE *ancestor[M_NAMELEN + 1] ;
-static length = 0 ;
+static int length = 0 ;
 static M_WCHAR name[M_NAMELEN + 1] ;
 
 if (init)
