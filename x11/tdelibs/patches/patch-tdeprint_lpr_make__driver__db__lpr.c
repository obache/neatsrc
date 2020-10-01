$NetBSD$

--- tdeprint/lpr/make_driver_db_lpr.c.orig	2020-04-10 23:08:30.000000000 +0000
+++ tdeprint/lpr/make_driver_db_lpr.c
@@ -47,7 +47,7 @@ void simplifyModel(const char *modelname
 	}
 }
 
-int parseApsFile(const char *filename, FILE *output)
+int parseApsFile(const char *filename, const char *orign, const char *metadata, FILE *output)
 {
 	FILE	*apsfile;
 	char	buf[256], modelname[256];
@@ -127,7 +127,7 @@ char* nextWord(char *c)
 	return d;
 }
 
-int parseIfhpFile(const char *filename, FILE *output)
+int parseIfhpFile(const char *filename, const char *orign, const char *metadata, FILE *output)
 {
 	char	buf[1024];
 	FILE	*in;
