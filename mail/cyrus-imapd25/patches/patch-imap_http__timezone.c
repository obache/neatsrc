$NetBSD$

* libical >= 3.0 API
* fix size type mismatch

--- imap/http_timezone.c.orig	2017-05-09 00:40:13.000000000 +0000
+++ imap/http_timezone.c
@@ -388,7 +388,7 @@ static int action_list(struct transactio
 	param = hash_lookup("changedsince", &txn->req_qparams);
 	if (param) {
 	    changedsince = icaltime_from_string(param->s);
-	    if (param->next || !changedsince.is_utc) {  /* once only, UTC */
+	    if (param->next || !icaltime_is_utc(changedsince)) {  /* once only, UTC */
 		return json_error_response(txn, TZ_INVALID_CHANGEDSINCE,
 					   param, &changedsince);
 	    }
@@ -396,7 +396,7 @@ static int action_list(struct transactio
 
 	name = hash_lookup("tzid", &txn->req_qparams);
 	if (name) {
-	    if (changedsince.is_utc) {
+	    if (icaltime_is_utc(changedsince)) {
 		return json_error_response(txn, TZ_INVALID_TZID,
 					   param, &changedsince);
 	    }
@@ -589,7 +589,7 @@ static const struct observance *truncate
 
 	/* Adjust DTSTART observance to UTC */
 	icaltime_adjust(&obs.onset, 0, 0, 0, -obs.offset_from);
-	obs.onset.is_utc = 1;
+	icaltime_set_timezone(&obs.onset, icaltimezone_get_utc_timezone());
 
 	/* Check DTSTART vs window close */
 	if (!icaltime_is_null_time(end) &&
@@ -651,7 +651,7 @@ static const struct observance *truncate
 		if (!infinite) {
 		    /* Adjust UNTIL to local time (for iterator) */
 		    icaltime_adjust(&rrule.until, 0, 0, 0, obs.offset_from);
-		    rrule.until.is_utc = 0;
+		    icaltime_set_timezone(&rrule.until, NULL);
 		}
 
 		if (trunc_dtstart) {
@@ -675,7 +675,7 @@ static const struct observance *truncate
 
 		    /* Adjust observance to UTC */
 		    icaltime_adjust(&obs.onset, 0, 0, 0, -obs.offset_from);
-		    obs.onset.is_utc = 1;
+		    icaltime_set_timezone(&obs.onset, icaltimezone_get_utc_timezone());
 
 		    if (trunc_until && icaltime_compare(obs.onset, end) > 0) {
 			/* Observance is on/after window close */
@@ -776,7 +776,7 @@ static const struct observance *truncate
 
 	    /* Adjust observance to UTC */
 	    icaltime_adjust(&obs.onset, 0, 0, 0, -obs.offset_from);
-	    obs.onset.is_utc = 1;
+	    icaltime_set_timezone(&obs.onset, icaltimezone_get_utc_timezone());
 
 	    if (!icaltime_is_null_time(end) &&
 		icaltime_compare(obs.onset, end) >= 0) {
@@ -880,7 +880,7 @@ static const struct observance *truncate
 	    case ICAL_DTSTART_PROPERTY:
 		/* Adjust window open to local time */
 		icaltime_adjust(&start, 0, 0, 0, tombstone.offset_from);
-		start.is_utc = 0;
+		icaltime_set_timezone(&start, NULL);
 
 		icalproperty_set_dtstart(prop, start);
 		break;
@@ -1037,7 +1037,7 @@ static int action_get(struct transaction
     if (txn->meth != METH_HEAD) {
 	static struct buf pathbuf = BUF_INITIALIZER;
 	const char *path, *proto, *host, *msg_base = NULL;
-	unsigned long msg_size = 0;
+	size_t msg_size = 0;
 	icalcomponent *ical, *vtz;
 	icalproperty *prop;
 	int fd;
@@ -1160,7 +1160,7 @@ static int action_expand(struct transact
     param = hash_lookup("changedsince", &txn->req_qparams);
     if (param) {
 	changedsince = icaltime_from_string(param->s);
-	if (param->next || !changedsince.is_utc) {  /* once only, UTC */
+	if (param->next || !icaltime_is_utc(changedsince)) {  /* once only, UTC */
 	    return json_error_response(txn, TZ_INVALID_CHANGEDSINCE,
 				       param, &changedsince);
 	}
@@ -1171,13 +1171,13 @@ static int action_expand(struct transact
 	return json_error_response(txn, TZ_INVALID_START, param, NULL);
 
     start = icaltime_from_string(param->s);
-    if (!start.is_utc)  /* MUST be UTC */
+    if (!icaltime_is_utc(start))  /* MUST be UTC */
 	return json_error_response(txn, TZ_INVALID_START, param, &start);
 
     param = hash_lookup("end", &txn->req_qparams);
     if (param) {
 	end = icaltime_from_string(param->s);
-	if (param->next || !end.is_utc  /* once only, UTC */
+	if (param->next || !icaltime_is_utc(end)  /* once only, UTC */
 	    || icaltime_compare(end, start) <= 0) {  /* end MUST be > start */
 	    return json_error_response(txn, TZ_INVALID_END, param, &end);
 	}
@@ -1250,7 +1250,7 @@ static int action_expand(struct transact
     if (txn->meth != METH_HEAD) {
 	static struct buf pathbuf = BUF_INITIALIZER;
 	const char *path, *msg_base = NULL;
-	unsigned long msg_size = 0;
+	size_t msg_size = 0;
 	icalcomponent *ical, *vtz;
 	const struct observance *proleptic;
 	char dtstamp[21];
@@ -1435,7 +1435,7 @@ static int json_error_response(struct tr
     else if (param->next) fmt = "multiple %s parameters";
     else if (!param->s || !param->s[0]) fmt = "missing %s value";
     else if (!time) fmt = "unknown %s value";
-    else if (!time->is_utc) fmt = "invalid %s UTC value";
+    else if (!icaltime_is_utc(*time)) fmt = "invalid %s UTC value";
 
     switch (tz_code) {
     case TZ_INVALID_TZID:
