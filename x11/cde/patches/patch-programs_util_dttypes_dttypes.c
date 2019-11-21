$NetBSD$

* declar function `usage` befure its usage

--- programs/util/dttypes/dttypes.c.orig	2019-10-12 21:43:45.000000000 +0000
+++ programs/util/dttypes/dttypes.c
@@ -353,6 +353,12 @@ rec_list(List *l)
 	}
 }
 
+int usage(void)
+{
+	fprintf(stderr, "%s", catgets(dtcatd, 1, 25, "usage:  dttypes [-help]\n\tdttypes [-type filename]\n\tdttypes [-db database] [-w [rec_name regexp] [fld_name regexp]\n\t\t\t[fld_value regexp]]\n\t\t[-l [rec_name] [rec_info] [fld_name regexp] [fld_value]]\n"));
+	exit(1);
+}
+
 int
 parse_args(List *l, int argc, char **argv)
 {
@@ -586,12 +592,6 @@ parse_args(List *l, int argc, char **arg
 	return(1);
 }
 
-int usage(void)
-{
-	fprintf(stderr, "%s", catgets(dtcatd, 1, 25, "usage:  dttypes [-help]\n\tdttypes [-type filename]\n\tdttypes [-db database] [-w [rec_name regexp] [fld_name regexp]\n\t\t\t[fld_value regexp]]\n\t\t[-l [rec_name] [rec_info] [fld_name regexp] [fld_value]]\n"));
-	exit(1);
-}
-
 int
 main(int argc, char **argv)
 {
