$NetBSD$

--- imap/http_timezone.c.orig	2015-05-08 03:49:52.000000000 +0000
+++ imap/http_timezone.c
@@ -1037,7 +1037,7 @@ static int action_get(struct transaction
     if (txn->meth != METH_HEAD) {
 	static struct buf pathbuf = BUF_INITIALIZER;
 	const char *path, *proto, *host, *msg_base = NULL;
-	unsigned long msg_size = 0;
+	size_t msg_size = 0;
 	icalcomponent *ical, *vtz;
 	icalproperty *prop;
 	int fd;
@@ -1250,7 +1250,7 @@ static int action_expand(struct transact
     if (txn->meth != METH_HEAD) {
 	static struct buf pathbuf = BUF_INITIALIZER;
 	const char *path, *msg_base = NULL;
-	unsigned long msg_size = 0;
+	size_t msg_size = 0;
 	icalcomponent *ical, *vtz;
 	const struct observance *proleptic;
 	char dtstamp[21];
