$NetBSD$

--- imap/caldav_db.c.orig	2020-08-24 00:27:42.000000000 +0000
+++ imap/caldav_db.c
@@ -912,8 +912,8 @@ static int _add_shareacls(const mbentry_
 
         cyrus_acl_strtomask(rightstr, &access);
 
-        unsigned long long have = (unsigned long long)hash_lookup(userid, &share->user_access);
-        unsigned long long set = have;
+        uintptr_t have = (uintptr_t)hash_lookup(userid, &share->user_access);
+        uintptr_t set = have;
 
         // if it's the principal, we have each user with principal read access
         if (isprincipal) {
@@ -943,7 +943,7 @@ static int _add_shareacls(const mbentry_
 static void _update_acls(const char *userid, void *data, void *rock)
 {
     struct shareacls_rock *share = rock;
-    unsigned long long aclstatus = (unsigned long long)data;
+    uintptr_t aclstatus = (uintptr_t)data;
 
     if ((aclstatus & CALSHARE_WANTSCHED) && !(aclstatus & CALSHARE_HAVESCHED)) {
         cyrus_acl_set(&share->newoutboxacl, userid, ACL_MODE_ADD, (DACL_INVITE|DACL_REPLY), NULL, NULL);
