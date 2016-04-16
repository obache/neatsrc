$NetBSD$

* avoid to conflict with std getline(3)

--- config/makedepend/main.c.orig	1997-06-30 12:33:26.000000000 +0000
+++ config/makedepend/main.c
@@ -548,7 +548,7 @@ match(str, list)
  * Get the next line.  We only return lines beginning with '#' since that
  * is all this program is ever interested in.
  */
-char *getline(filep)
+char *my_getline(filep)
 	register struct filepointer	*filep;
 {
 	register char	*p,	/* walking pointer */
