$NetBSD$

* prevent mixed usage of gdbm and its ndbm compat functions

--- gdbm/cldbm.c.orig	2006-03-19 12:40:39.000000000 +0000
+++ gdbm/cldbm.c
@@ -148,7 +148,7 @@ value caml_dbm_open(value vfile, value v
 /* Dbm.close: t -> unit */
 value caml_dbm_close(value vdb)       /* ML */
 {
-  dbm_close(extract_dbm(vdb));
+  gdbm_close(extract_dbm(vdb));
   DBM_val(vdb) = NULL;
   return Val_unit;
 }
@@ -201,7 +201,7 @@ value caml_dbm_replace(value vdb, value 
   content.dptr = String_val(vcontent);
   content.dsize = string_length(vcontent);
 
-  rt = dbm_store(extract_dbm(vdb), key, content, GDBM_REPLACE);
+  rt = gdbm_store(extract_dbm(vdb), key, content, GDBM_REPLACE);
 
   switch(rt) {
   case 0:
@@ -218,7 +218,7 @@ value caml_dbm_delete(value vdb, value v
   key.dptr = String_val(vkey);
   key.dsize = string_length(vkey);
 
-  rt = dbm_delete(extract_dbm(vdb), key); 
+  rt = gdbm_delete(extract_dbm(vdb), key); 
 
   if (rt < 0)
     raise_dbm("dbm_delete");
