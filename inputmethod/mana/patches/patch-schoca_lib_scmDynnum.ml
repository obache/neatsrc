$NetBSD$

* fix deprecated usage

--- schoca/lib/scmDynnum.ml.orig	2004-11-13 18:35:51.000000000 +0000
+++ schoca/lib/scmDynnum.ml
@@ -429,7 +429,7 @@ let rec of_string ?(radix = default_radi
 		  '#' ->
 		    if prefix then
 		      let nnindex = succ nindex in
-			match Char.lowercase (String.get s nindex) with
+			match Char.lowercase_ascii (String.get s nindex) with
 			  | 'e' -> iter prefix radix number nnindex
 			  | 'i' -> iter prefix radix (inexact number) nnindex			    
 			  | 'b' -> iter prefix (of_int 2) number nnindex
@@ -444,7 +444,7 @@ let rec of_string ?(radix = default_radi
 		      add_next_digit digit_value
 		| 'a' .. 'f' 
 		| 'A' .. 'F' as c when int_of radix = 16 ->
-		    let digit_value = Char.code (Char.lowercase c) - a_code + 10 in
+		    let digit_value = Char.code (Char.lowercase_ascii c) - a_code + 10 in
 		      add_next_digit digit_value
 		| '+' -> 
 		    if prefix then iter false radix number nindex
