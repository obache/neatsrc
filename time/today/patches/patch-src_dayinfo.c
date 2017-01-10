$NetBSD$

--- src/dayinfo.c.orig	2015-08-24 08:24:18.000000000 +0000
+++ src/dayinfo.c
@@ -142,7 +142,7 @@ void dayinfo(int year, int month, int da
 int main(int argc, char **argv)
 {
 	int		year, month, day;
-	long	tms;
+	time_t	tms;
 	struct tm	*ntm;
 
 	if (argc < 2) {
