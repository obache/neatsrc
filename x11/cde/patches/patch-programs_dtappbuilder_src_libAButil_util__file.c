$NetBSD$

--- programs/dtappbuilder/src/libAButil/util_file.c.orig	2015-05-09 23:09:11.000000000 +0000
+++ programs/dtappbuilder/src/libAButil/util_file.c
@@ -432,7 +432,7 @@ util_cvt_path_to_relative(
 	}
 	else
 	{
-	    while ((*rightmost_slash == '/') && (*rightmost_slash != NULL))
+	    while ((*rightmost_slash == '/') && (*rightmost_slash != '\0'))
 	    {
 	        ++rightmost_slash;
 	    }
