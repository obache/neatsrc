$NetBSD$

* fix ctype usage

--- common/phones/atgen.c.orig	2011-12-02 14:53:04.000000000 +0000
+++ common/phones/atgen.c
@@ -252,7 +252,7 @@ static int reply_simpletext(char *req, c
 			while (resp[i] && resp[i++] != ':')
 				;
 		}
-		while (isspace(resp[i]))
+		while (isspace((unsigned char)resp[i]))
 			i++;
 		snprintf(dest, maxlength, "%s", strip_quotes(resp + i));
 		return 1;
