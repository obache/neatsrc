$NetBSD$

* avoid to conflict with std getline(3)

--- config/makedepend/def.h.orig	1997-06-30 12:33:23.000000000 +0000
+++ config/makedepend/def.h
@@ -137,7 +137,7 @@ char			*realloc();
 
 char			*copy();
 char			*base_name();
-char			*getline();
+char			*my_getline();
 struct symtab		**slookup();
 struct symtab		**isdefined();
 struct symtab		**fdefined();
