$NetBSD$

* fix deprecated usage

--- schoca/lib/scmTypes.ml.orig	2005-11-19 07:09:41.000000000 +0000
+++ schoca/lib/scmTypes.ml
@@ -510,7 +510,7 @@ let vector_of_datum =
 
 let vector_of_list list = 
   let len = length list in
-  let a = Array.create len Nil in
+  let a = Array.make len Nil in
   let idx = ref ~-1 in
     iter (fun elem -> 
 	    incr idx; 
