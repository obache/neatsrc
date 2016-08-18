$NetBSD$

* Fix warnings about incompatible callback types 
* Set NOUSER error same as other db backend
* Make sure to raise FAIL with db open error

--- sasldb/db_ndbm.c.orig	2012-01-27 23:31:36.000000000 +0000
+++ sasldb/db_ndbm.c
@@ -92,7 +92,7 @@ int _sasldb_getdata(const sasl_utils_t *
   }
 
   if (utils->getcallback(conn, SASL_CB_GETOPT,
-                        &getopt, &cntxt) == SASL_OK) {
+                        (sasl_callback_ft *)&getopt, &cntxt) == SASL_OK) {
       const char *p;
       if (getopt(cntxt, NULL, "sasldb_path", &p, NULL) == SASL_OK 
 	  && p != NULL && *p != 0) {
@@ -109,7 +109,9 @@ int _sasldb_getdata(const sasl_utils_t *
   dkey.dsize = key_len;
   dvalue = dbm_fetch(db, dkey);
   if (! dvalue.dptr) {
-      utils->seterror(cntxt, 0, "no user in db");
+      utils->seterror(cntxt, SASL_NOLOG,
+		      "user: %s@%s property: %s not found in db",
+		      authid, realm, propName);
       result = SASL_NOUSER;
       goto cleanup;
   }
@@ -170,7 +172,7 @@ int _sasldb_putdata(const sasl_utils_t *
   }
 
   if (utils->getcallback(conn, SASL_CB_GETOPT,
-			 &getopt, &cntxt) == SASL_OK) {
+			 (sasl_callback_ft *)&getopt, &cntxt) == SASL_OK) {
       const char *p;
       if (getopt(cntxt, NULL, "sasldb_path", &p, NULL) == SASL_OK 
 	  && p != NULL && *p != 0) {
@@ -186,6 +188,7 @@ int _sasldb_putdata(const sasl_utils_t *
 		 "SASL error opening password file. "
 		 "Do you have write permissions?\n");
       utils->seterror(conn, 0, "Could not open db for write");
+      result = SASL_FAIL;
       goto cleanup;
   }
   dkey.dptr = key;
@@ -234,7 +237,7 @@ int _sasl_check_db(const sasl_utils_t *u
     if(!utils) return SASL_BADPARAM;
 
     if (utils->getcallback(conn, SASL_CB_GETOPT,
-			   &getopt, &cntxt) == SASL_OK) {
+			   (sasl_callback_ft *)&getopt, &cntxt) == SASL_OK) {
 	const char *p;
 	if (getopt(cntxt, NULL, "sasldb_path", &p, NULL) == SASL_OK 
 	    && p != NULL && *p != 0) {
@@ -249,7 +252,7 @@ int _sasl_check_db(const sasl_utils_t *u
     }
 
     ret = utils->getcallback(NULL, SASL_CB_VERIFYFILE,
-			     &vf, &cntxt);
+			     (sasl_callback_ft *)&vf, &cntxt);
     if(ret != SASL_OK) {
 	utils->seterror(conn, 0,
 			"No verifyfile callback");
@@ -311,7 +314,7 @@ sasldb_handle _sasldb_getkeyhandle(const
     }
 
     if (utils->getcallback(conn, SASL_CB_GETOPT,
-			   &getopt, &cntxt) == SASL_OK) {
+			   (sasl_callback_ft *)&getopt, &cntxt) == SASL_OK) {
 	const char *p;
 	if (getopt(cntxt, NULL, "sasldb_path", &p, NULL) == SASL_OK 
 	    && p != NULL && *p != 0) {
