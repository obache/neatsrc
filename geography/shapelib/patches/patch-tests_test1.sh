$NetBSD$

* portability fix

--- tests/test1.sh.orig	2016-12-05 10:43:10.000000000 +0000
+++ tests/test1.sh
@@ -33,7 +33,7 @@ echo -----------------------------------
 ) > "$testdir/s1.out"
 
 result="$(diff "$testdir/s1.out" "$testdir/stream1.out")"
-if [ "$result" == "" ]; then
+if [ "$result" = "" ]; then
 	echo "******* Stream 1 Succeeded *********"
 	rm "$testdir/s1.out"
 	exit 0
