$NetBSD$

--- tests/playTests.sh.orig	2020-12-19 00:39:42.000000000 +0000
+++ tests/playTests.sh
@@ -114,13 +114,13 @@ esac
 case "$UNAME" in
   Darwin) MD5SUM="md5 -r" ;;
   FreeBSD) MD5SUM="gmd5sum" ;;
-  OpenBSD) MD5SUM="md5" ;;
+  NetBSD | OpenBSD) MD5SUM="md5" ;;
   *) MD5SUM="md5sum" ;;
 esac
 
 MTIME="stat -c %Y"
 case "$UNAME" in
-    Darwin | FreeBSD | OpenBSD) MTIME="stat -f %m" ;;
+    Darwin | FreeBSD | NetBSD | OpenBSD) MTIME="stat -f %m" ;;
 esac
 
 DIFF="diff"
