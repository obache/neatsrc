$NetBSD$

* fix unwanted ","

--- lib/DtSearch/raima/dproto.h.orig	2019-10-12 21:43:45.000000000 +0000
+++ lib/DtSearch/raima/dproto.h
@@ -257,7 +257,7 @@ int d_recfrst(int, int);			/* recfrst.c 
 int d_reclast(int, int);			/* reclast.c */
 int d_reclock(int, char *, int); 	/* dblfcns.c */
 int d_reclstat(int, char *, int); 	/* dblfcns.c */
-int d_recover(const, char *);		/* recover.c */
+int d_recover(const char *);		/* recover.c */
 int d_recread(char *, int);		/* recread.c */
 int d_recset(int, int);   			/* recset.c */
 int d_recwrite(const char *, int); 	/* recwrite.c */
