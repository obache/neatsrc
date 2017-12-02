$NetBSD$

* from upstream fix

--- src/libspf2/spf_request.c.orig	2012-01-28 08:24:47.000000000 +0000
+++ src/libspf2/spf_request.c
@@ -246,6 +246,7 @@ SPF_request_query_record(SPF_request_t *
 	if (err != SPF_E_SUCCESS) {
 		if (spf_record)
 			SPF_record_free(spf_record);
+		SPF_i_done(spf_response, spf_response->result, spf_response->reason, spf_response->err);
 		return err;
 	}
 	/* Now, in theory, SPF_response_errors(spf_response) == 0 */
@@ -363,6 +364,8 @@ SPF_request_query_rcptto(SPF_request_t *
 	rcpt_to_dom = strchr(rcpt_to, '@');
 	if (rcpt_to_dom == NULL)
 		rcpt_to_dom = rcpt_to;
+	else
+		rcpt_to_dom++;
 	spf_request->cur_dom = rcpt_to_dom;
 
 	len = sizeof(SPF_VER_STR) + 64 + strlen(rcpt_to_dom);
