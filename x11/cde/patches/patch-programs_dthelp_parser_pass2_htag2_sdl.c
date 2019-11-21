$NetBSD$

* exactly declare as int

--- programs/dthelp/parser/pass2/htag2/sdl.c.orig	2019-11-16 02:06:11.000000000 +0000
+++ programs/dthelp/parser/pass2/htag2/sdl.c
@@ -6467,7 +6467,7 @@ static M_WCHAR *CycleEnt(LOGICAL init,
 {
 static M_TRIE *current ;
 static M_TRIE *ancestor[M_NAMELEN + 1] ;
-static length = 0 ;
+static int length = 0 ;
 static M_WCHAR name[M_NAMELEN + 1] ;
 
 if (init)
