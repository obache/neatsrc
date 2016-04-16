$NetBSD$

* avoid to conflict with std getline(3)

--- config/makedepend/parse.c.orig	1997-06-30 12:33:28.000000000 +0000
+++ config/makedepend/parse.c
@@ -40,7 +40,7 @@ gobble(filep, file, file_red)
 	register char	*line;
 	register int	type;
 
-	while (line = getline(filep)) {
+	while (line = my_getline(filep)) {
 		switch(type = deftype(line, filep, file_red, file, FALSE)) {
 		case IF:
 		case IFFALSE:
@@ -529,7 +529,7 @@ find_includes(filep, file, file_red, rec
 	register int	type;
 	boolean recfailOK;
 
-	while (line = getline(filep)) {
+	while (line = my_getline(filep)) {
 		switch(type = deftype(line, filep, file_red, file, TRUE)) {
 		case IF:
 		doif:
