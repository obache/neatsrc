$NetBSD$

* exactly declare as int

--- programs/dthelp/parser/pass1/parser/cyclent.c.orig	2019-11-16 02:06:11.000000000 +0000
+++ programs/dthelp/parser/pass1/parser/cyclent.c
@@ -40,7 +40,7 @@ M_WCHAR *m_cyclent(LOGICAL init, unsigne
 {
     static M_TRIE *current ;
     static M_TRIE *ancestor[M_NAMELEN + 1] ;
-    static length = 0 ;
+    static int length = 0 ;
     static M_WCHAR name[M_NAMELEN + 1] ;
 
     if (init) {
