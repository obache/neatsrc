$NetBSD$

* fix deprecated usage

--- schoca/lib/scmEval.ml.orig	2005-09-26 08:58:18.000000000 +0000
+++ schoca/lib/scmEval.ml
@@ -744,13 +744,13 @@ let scm_char_whitespace_p =
        | _ -> false)
 
 let scm_char_uppercase_p =
-  char_predicate (fun c -> c = Char.uppercase c)
+  char_predicate (fun c -> c = Char.uppercase_ascii c)
        
 let scm_char_lowercase_p =
-  char_predicate (fun c -> c = Char.lowercase c)
+  char_predicate (fun c -> c = Char.lowercase_ascii c)
 
 let chr_ci_cmp cmp c1 c2 = 
-  cmp (Char.lowercase c1) (Char.lowercase c2)
+  cmp (Char.lowercase_ascii c1) (Char.lowercase_ascii c2)
 
 let scm_char_ci_eq_p = char_predicate_of_list (chr_ci_cmp (=))
 let scm_char_ci_greater_p = char_predicate_of_list (chr_ci_cmp (>))
@@ -810,7 +810,7 @@ let scm_string_greater_or_equal_p = stri
 let scm_string_less_or_equal_p = string_predicate_of_list (<=)
 
 let str_ci_cmp cmp s1 s2 =
-  cmp (String.lowercase s1) (String.lowercase s2)
+  cmp (String.lowercase_ascii s1) (String.lowercase_ascii s2)
 
 let scm_string_ci_eq_p = string_predicate_of_list (str_ci_cmp (=))
 let scm_string_ci_greater_p = string_predicate_of_list (str_ci_cmp (>))
@@ -875,7 +875,7 @@ let scm_make_vector args =
   and initial = 
     if simple_cell args then Nil
     else cadr args in
-    Vector (Array.create (exact_int_of_datum size) initial)
+    Vector (Array.make (exact_int_of_datum size) initial)
 
 let scm_getenv =
   simple_cmd_1 
