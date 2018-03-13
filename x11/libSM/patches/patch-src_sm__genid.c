$NetBSD$

* Fix uuid_to_string(3) type
* Get rid of strcpy() in the HAVE_UUID_CREATE case

--- src/sm_genid.c.orig	2013-09-08 06:05:20.000000000 +0000
+++ src/sm_genid.c
@@ -107,19 +107,18 @@ SmsGenerateClientID(SmsConn smsConn)
 {
 #if defined(HAVE_UUID_CREATE)
     char *id;
-    char **temp;
+    char *temp;
     uuid_t uuid;
     uint32_t status;
+    size_t len;
 
     uuid_create(&uuid, &status);
 
     uuid_to_string(&uuid, &temp, &status);
 
-    if ((id = malloc (strlen (temp) + 2)) != NULL)
-    {
-        id[0] = '2';
-        strcpy (id+1, temp);
-    }
+    len = strlen(temp) + 2;
+    if ((id = malloc (len)) != NULL)
+        snprintf(id, len, "2%s", temp);
 
     free(temp);
 
