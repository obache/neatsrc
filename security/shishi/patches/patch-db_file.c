$NetBSD$

* for size_t != int

--- db/file.c.orig	2013-04-02 22:52:55.000000000 +0000
+++ db/file.c
@@ -435,7 +435,7 @@ read_key (Shisa * dbh,
 
   memset (&tmpkey, 0, sizeof (tmpkey));
 
-  rc = fscanf (fh, "%u %u %u %u %u %u", &tmpkey.etype, &tmpkey.keylen,
+  rc = fscanf (fh, "%u %zu %zu %zu %u %u", &tmpkey.etype, &tmpkey.keylen,
 	       &tmpkey.saltlen, &tmpkey.str2keyparamlen, &passwdlen,
 	       &tmpkey.priority);
   if (rc != 5 && rc != 6)
