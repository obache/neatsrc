$NetBSD$

* fix typo in function prototype name

--- src/sj3serv/sj3serv.h.orig	2010-02-14 12:20:33.000000000 +0000
+++ src/sj3serv/sj3serv.h
@@ -137,7 +137,7 @@ void preopen_dict();
 int check_user(char *, char *);
 
 /* priv.c */
-void set_priv(const char *);
+void priv_set(const char *);
 
 /* timestamp.c */
 extern char *time_stamp;
