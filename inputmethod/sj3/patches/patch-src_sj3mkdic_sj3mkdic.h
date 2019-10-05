$NetBSD$

* fix to match prototype with usage

--- src/sj3mkdic/sj3mkdic.h.orig	2010-02-14 12:20:37.000000000 +0000
+++ src/sj3mkdic/sj3mkdic.h
@@ -107,7 +107,7 @@ OffsetRec *real_ofsrec(u_char *);
 
 /* readline.c */
 int *readline();
-void setline(int (*)());
+void setline(void (*)(int *, int *, int, int *));
 
 /* string.c */
 int bubun_str(u_char *, int, u_char *, int);
