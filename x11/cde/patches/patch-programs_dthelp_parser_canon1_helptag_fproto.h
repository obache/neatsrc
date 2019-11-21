$NetBSD$

* missing declare

--- programs/dthelp/parser/canon1/helptag/fproto.h.orig	2019-11-16 02:06:11.000000000 +0000
+++ programs/dthelp/parser/canon1/helptag/fproto.h
@@ -47,6 +47,8 @@ void mb_echohead(char *p);
 
 void endhead(void);
 
+void chksnb(void);
+
 void esoutchar(M_WCHAR textchar);
 
 void vexoutchar(M_WCHAR textchar);
