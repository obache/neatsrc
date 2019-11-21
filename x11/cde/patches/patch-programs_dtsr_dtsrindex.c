$NetBSD$

* add missing things

--- programs/dtsr/dtsrindex.c.orig	2019-10-12 21:43:45.000000000 +0000
+++ programs/dtsr/dtsrindex.c
@@ -126,8 +126,10 @@
 
 extern void     find_keyword (char *cur_word, int vista_num);
 extern void     read_wordstr (struct or_hwordrec * glob_word, int vista_num);
+extern void     fillnew_wordrec (struct or_hwordrec * glob_word, int vista_num);
 extern void     write_wordstr (struct or_hwordrec * glob_word, int vista_num);
 extern void     fill_data1 (char *ch);
+extern void     init_user_interrupt (void);
 
 #define PROGNAME	"DTSRINDEX"
 
@@ -1359,7 +1361,7 @@ static void	load_into_bintree (
 /*                    MAIN                    */
 /*                                            */
 /**********************************************/
-main (int argc, char **argv)
+int	main (int argc, char **argv)
 {
     int			i;
     long		word_offset;	/* <-- PARG.offsetp */
