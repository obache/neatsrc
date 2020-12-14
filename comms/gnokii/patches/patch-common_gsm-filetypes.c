$NetBSD$

* Make inline to be static inline where relevant (to be compatible with C99)

--- common/gsm-filetypes.c.orig	2011-12-02 14:53:04.000000000 +0000
+++ common/gsm-filetypes.c
@@ -1409,7 +1409,7 @@ static int get_next_token(char *src, int
 #define GET_NEXT_TOKEN()	o = get_next_token(line + offset, ';')
 #define STORE_TOKEN(a)		strip_slashes(a, line + offset, sizeof(a) - 1, o - 1)
 
-inline int local_atoi(char *str, int len)
+static inline int local_atoi(char *str, int len)
 {
 	int retval;
 	char *aux = strndup(str, len);
