$NetBSD$

* fix deprecated usage

--- schoca/lib/scmLexer.mll.orig	2005-09-26 08:58:18.000000000 +0000
+++ schoca/lib/scmLexer.mll
@@ -50,7 +50,7 @@
       | "#f" | "#F" -> scm_false
       | _ -> invalid_arg "extract_boolean"
 
-  let extract_symbol = String.lowercase
+  let extract_symbol = String.lowercase_ascii
 
 
   let make_fast_sub_lexbuf = Lexing.from_string (* TODO: faster lexbuf is possible with shared string *)
