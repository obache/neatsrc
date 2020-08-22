$NetBSD$

* use a union for event parameter values rather than tyepecasting

--- imap/mboxevent.c.orig	2020-08-19 01:37:51.000000000 +0000
+++ imap/mboxevent.c
@@ -86,13 +86,13 @@
 #define QUOTA_EVENTS   (EVENT_QUOTA_EXCEED|EVENT_QUOTA_WITHIN|EVENT_QUOTA_CHANGE)
 
 
-#define FILL_STRING_PARAM(e,p,v) e->params[p].value = (uint64_t)v; \
+#define FILL_STRING_PARAM(e,p,v) e->params[p].value.s = v; \
 				 e->params[p].type = EVENT_PARAM_STRING; \
 				 e->params[p].filled = 1
-#define FILL_ARRAY_PARAM(e,p,v) e->params[p].value = (uint64_t)v; \
+#define FILL_ARRAY_PARAM(e,p,v) e->params[p].value.a = v; \
 				 e->params[p].type = EVENT_PARAM_ARRAY; \
 				 e->params[p].filled = 1
-#define FILL_UNSIGNED_PARAM(e,p,v) e->params[p].value = (uint64_t)v; \
+#define FILL_UNSIGNED_PARAM(e,p,v) e->params[p].value.u = v; \
 				  e->params[p].type = EVENT_PARAM_INT; \
 				  e->params[p].filled = 1
 
@@ -110,37 +110,37 @@ static struct mboxevent event_template =
 { 0,
   /* ordered to optimize the parsing of the notification message */
   {
-    /*  0 */ { EVENT_TIMESTAMP, "timestamp", EVENT_PARAM_STRING, 0, 0 },
+    /*  0 */ { EVENT_TIMESTAMP, "timestamp", EVENT_PARAM_STRING, { 0 }, 0 },
     /*  1 */ { EVENT_SERVICE, "service", EVENT_PARAM_STRING, 0, 0 },
-    /*  2 */ { EVENT_SERVER_ADDRESS, "serverAddress", EVENT_PARAM_STRING, 0, 0 },
-    /*  3 */ { EVENT_CLIENT_ADDRESS, "clientAddress", EVENT_PARAM_STRING, 0, 0 },
-    /*  4 */ { EVENT_OLD_MAILBOX_ID, "oldMailboxID", EVENT_PARAM_STRING, 0, 0 },
-    /*  5 */ { EVENT_OLD_UIDSET, "vnd.cmu.oldUidset", EVENT_PARAM_STRING, 0, 0 },
-    /*  6 */ { EVENT_MAILBOX_ID, "mailboxID", EVENT_PARAM_STRING, 0, 0 },
-    /*  7 */ { EVENT_URI, "uri", EVENT_PARAM_STRING, 0, 0 },
-    /*  8 */ { EVENT_MODSEQ, "modseq", EVENT_PARAM_INT, 0, 0 },
-    /*  9 */ { EVENT_QUOTA_STORAGE, "diskQuota", EVENT_PARAM_INT, 0, 0 },
-    /* 10 */ { EVENT_DISK_USED, "diskUsed", EVENT_PARAM_INT, 0, 0 },
-    /* 11 */ { EVENT_QUOTA_MESSAGES, "maxMessages", EVENT_PARAM_INT, 0, 0 },
-    /* 12 */ { EVENT_MESSAGES, "messages", EVENT_PARAM_INT, 0, 0 },
-    /* 13 */ { EVENT_UNSEEN_MESSAGES, "vnd.cmu.unseenMessages", EVENT_PARAM_INT, 0, 0 },
-    /* 14 */ { EVENT_UIDNEXT, "uidnext", EVENT_PARAM_INT, 0, 0 },
-    /* 15 */ { EVENT_UIDSET, "uidset", EVENT_PARAM_STRING, 0, 0 },
-    /* 16 */ { EVENT_MIDSET, "vnd.cmu.midset", EVENT_PARAM_STRING, 0, 0 },
-    /* 17 */ { EVENT_FLAG_NAMES, "flagNames", EVENT_PARAM_STRING, 0, 0 },
-    /* 18 */ { EVENT_PID, "pid", EVENT_PARAM_INT, 0, 0 },
-    /* 19 */ { EVENT_ACL_SUBJECT, "aclSubject", EVENT_PARAM_STRING, 0, 0 },
-    /* 20 */ { EVENT_ACL_RIGHTS, "aclRights", EVENT_PARAM_STRING, 0, 0 },
-    /* 21 */ { EVENT_USER, "user", EVENT_PARAM_STRING, 0, 0 },
-    /* 22 */ { EVENT_MESSAGE_SIZE, "messageSize", EVENT_PARAM_INT, 0, 0 },
-    /* 23 */ { EVENT_MBTYPE, "vnd.cmu.mbtype", EVENT_PARAM_STRING, 0, 0 },
-    /* 24 */ { EVENT_DAV_FILENAME, "vnd.cmu.davFilename", EVENT_PARAM_STRING, 0, 0 },
-    /* 25 */ { EVENT_DAV_UID, "vnd.cmu.davUid", EVENT_PARAM_STRING, 0, 0 },
-    /* 26 */ { EVENT_ENVELOPE, "vnd.cmu.envelope", EVENT_PARAM_STRING, 0, 0 },
-    /* 27 */ { EVENT_SESSIONID, "vnd.cmu.sessionId", EVENT_PARAM_STRING, 0, 0 },
-    /* 28 */ { EVENT_BODYSTRUCTURE, "bodyStructure", EVENT_PARAM_STRING, 0, 0 },
+    /*  2 */ { EVENT_SERVER_ADDRESS, "serverAddress", EVENT_PARAM_STRING, { 0 }, 0 },
+    /*  3 */ { EVENT_CLIENT_ADDRESS, "clientAddress", EVENT_PARAM_STRING, { 0 }, 0 },
+    /*  4 */ { EVENT_OLD_MAILBOX_ID, "oldMailboxID", EVENT_PARAM_STRING, { 0 }, 0 },
+    /*  5 */ { EVENT_OLD_UIDSET, "vnd.cmu.oldUidset", EVENT_PARAM_STRING, { 0 }, 0 },
+    /*  6 */ { EVENT_MAILBOX_ID, "mailboxID", EVENT_PARAM_STRING, { 0 }, 0 },
+    /*  7 */ { EVENT_URI, "uri", EVENT_PARAM_STRING, { 0 }, 0 },
+    /*  8 */ { EVENT_MODSEQ, "modseq", EVENT_PARAM_INT, { 0 }, 0 },
+    /*  9 */ { EVENT_QUOTA_STORAGE, "diskQuota", EVENT_PARAM_INT, { 0 }, 0 },
+    /* 10 */ { EVENT_DISK_USED, "diskUsed", EVENT_PARAM_INT, { 0 }, 0 },
+    /* 11 */ { EVENT_QUOTA_MESSAGES, "maxMessages", EVENT_PARAM_INT, { 0 }, 0 },
+    /* 12 */ { EVENT_MESSAGES, "messages", EVENT_PARAM_INT, { 0 }, 0 },
+    /* 13 */ { EVENT_UNSEEN_MESSAGES, "vnd.cmu.unseenMessages", EVENT_PARAM_INT, { 0 }, 0 },
+    /* 14 */ { EVENT_UIDNEXT, "uidnext", EVENT_PARAM_INT, { 0 }, 0 },
+    /* 15 */ { EVENT_UIDSET, "uidset", EVENT_PARAM_STRING, { 0 }, 0 },
+    /* 16 */ { EVENT_MIDSET, "vnd.cmu.midset", EVENT_PARAM_STRING, { 0 }, 0 },
+    /* 17 */ { EVENT_FLAG_NAMES, "flagNames", EVENT_PARAM_STRING, { 0 }, 0 },
+    /* 18 */ { EVENT_PID, "pid", EVENT_PARAM_INT, { 0 }, 0 },
+    /* 19 */ { EVENT_ACL_SUBJECT, "aclSubject", EVENT_PARAM_STRING, { 0 }, 0 },
+    /* 20 */ { EVENT_ACL_RIGHTS, "aclRights", EVENT_PARAM_STRING, { 0 }, 0 },
+    /* 21 */ { EVENT_USER, "user", EVENT_PARAM_STRING, { 0 }, 0 },
+    /* 22 */ { EVENT_MESSAGE_SIZE, "messageSize", EVENT_PARAM_INT, { 0 }, 0 },
+    /* 23 */ { EVENT_MBTYPE, "vnd.cmu.mbtype", EVENT_PARAM_STRING, { 0 }, 0 },
+    /* 24 */ { EVENT_DAV_FILENAME, "vnd.cmu.davFilename", EVENT_PARAM_STRING, { 0 }, 0 },
+    /* 25 */ { EVENT_DAV_UID, "vnd.cmu.davUid", EVENT_PARAM_STRING, { 0 }, 0 },
+    /* 26 */ { EVENT_ENVELOPE, "vnd.cmu.envelope", EVENT_PARAM_STRING, { 0 }, 0 },
+    /* 27 */ { EVENT_SESSIONID, "vnd.cmu.sessionId", EVENT_PARAM_STRING, { 0 }, 0 },
+    /* 28 */ { EVENT_BODYSTRUCTURE, "bodyStructure", EVENT_PARAM_STRING, { 0 }, 0 },
     /* always at end to let the parser to easily truncate this part */
-    /* 29 */ { EVENT_MESSAGE_CONTENT, "messageContent", EVENT_PARAM_STRING, 0, 0 }
+    /* 29 */ { EVENT_MESSAGE_CONTENT, "messageContent", EVENT_PARAM_STRING, { 0 }, 0 }
   },
   STRARRAY_INITIALIZER, { 0, 0 }, NULL, STRARRAY_INITIALIZER, NULL, NULL, NULL
 };
@@ -310,7 +310,7 @@ EXPORTED void mboxevent_free(struct mbox
 
     for (i = 0; i <= MAX_PARAM; i++) {
 	if (event->params[i].filled && event->params[i].type == EVENT_PARAM_STRING)
-	    free((char *)event->params[i].value);
+	    free(event->params[i].value.s);
     }
 
     if (event->prev)
@@ -828,8 +828,7 @@ void mboxevent_extract_content(struct mb
 			       const struct index_record *record, FILE* content)
 {
     const char *base = NULL;
-    unsigned long len = 0;
-    size_t offset, size, truncate;
+    size_t offset, size, truncate, len = 0;
 
     if (!event)
 	return;
@@ -1141,7 +1140,7 @@ static char *json_formatter(enum event_t
 	switch (params[param].id) {
 	case EVENT_CLIENT_ADDRESS:
 	    /* come from saslprops structure */
-	    val = strdup((char *)params[param].value);
+	    val = strdup(params[param].value.s);
 	    ptr = strchr(val, ';');
 	    *ptr++ = '\0';
 
@@ -1154,7 +1153,7 @@ static char *json_formatter(enum event_t
 	    break;
 	case EVENT_SERVER_ADDRESS:
 	    /* come from saslprops structure */
-	    val = strdup((char *)params[param].value);
+	    val = strdup(params[param].value.s);
 	    ptr = strchr(val, ';');
 	    *ptr++ = '\0';
 
@@ -1169,15 +1168,15 @@ static char *json_formatter(enum event_t
 	    switch (params[param].type) {
 	    case EVENT_PARAM_INT:
 		json_object_set_new(event_json, params[param].name,
-				    json_integer(params[param].value));
+				    json_integer(params[param].value.u));
 		break;
 	    case EVENT_PARAM_STRING:
 		json_object_set_new(event_json, params[param].name,
-				    json_string((char *)params[param].value));
+				    json_string((char *)params[param].value.s));
 		break;
 	    case EVENT_PARAM_ARRAY:
 		jarray = json_array();
-		strarray_t *sarray = (strarray_t *)params[param].value;
+		strarray_t *sarray = params[param].value.a;
 		int i;
 
 		for (i = 0; i < strarray_size(sarray); i++) {
