$NetBSD$

* avoid to conflict with std getline(3)

--- programs/Xserver/hw/xfree86/xf86config/cards.c.orig	2000-01-10 22:04:21.000000000 +0000
+++ programs/Xserver/hw/xfree86/xf86config/cards.c
@@ -68,7 +68,7 @@ Card card[MAX_CARDS];
 void sort_database();
 
 
-static int getline(f, l)
+static int my_getline(f, l)
 FILE *f;
 char *l;
 {
@@ -169,7 +169,7 @@ int parse_database() {
 	cardInFile = -1;
 
 	for (;;) {
-		if (getline(f, buf))
+		if (my_getline(f, buf))
 			break;
 		lineno++;
 		if (buf[0] == '#')
