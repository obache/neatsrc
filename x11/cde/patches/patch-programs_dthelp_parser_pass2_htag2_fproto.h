$NetBSD$

* fix a typo

--- programs/dthelp/parser/pass2/htag2/fproto.h.orig	2019-11-16 02:06:11.000000000 +0000
+++ programs/dthelp/parser/pass2/htag2/fproto.h
@@ -54,7 +54,7 @@ void OpenTag(LOGICAL hasAttributes,
 
 void CloseTag(LOGICAL newlineOK);
 
-void ImpliedlAttribute(char    *name,
+void ImpliedAttribute(char    *name,
   M_WCHAR *value);
 
 void RequiredAttribute(char    *name,
