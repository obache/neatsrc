$NetBSD$

--- programs/dtcm/server/rtable4.c.orig	2015-05-09 23:09:11.000000000 +0000
+++ programs/dtcm/server/rtable4.c
@@ -1413,6 +1413,7 @@ _DtCm_rtable_gmtoff_4_svc(void *args, st
 #if !defined(CSRG_BASED)
 	extern long timezone;
 #else
+	time_t ctime;
 	struct tm *t;
 #endif
 
@@ -1420,7 +1421,8 @@ _DtCm_rtable_gmtoff_4_svc(void *args, st
 		fprintf(stderr, "_DtCm_rtable_gmtoff_4_svc called\n");
 
 #if defined(CSRG_BASED)
-	t = localtime(time(NULL));
+	ctime = time(NULL);
+	t = localtime(&ctime);
 	gmtoff = t->tm_gmtoff;
 #else
 	gmtoff = timezone;
