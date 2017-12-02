$NetBSD$

* from upstream fix

--- src/libspf2/spf_server.c.orig	2012-01-28 08:24:47.000000000 +0000
+++ src/libspf2/spf_server.c
@@ -383,14 +383,26 @@ retry:
 			if (spf_server->debug > 0)
 				SPF_debugf("get_record(%s): TRY_AGAIN", domain);
 			SPF_dns_rr_free(rr_txt);
+			if (rr_type == ns_t_spf) {
+				rr_type = ns_t_txt;
+				goto retry;
+			}
+			spf_response->result = SPF_RESULT_TEMPERROR;
+			spf_response->reason = SPF_REASON_FAILURE;
 			return SPF_response_add_error(spf_response, SPF_E_DNS_ERROR,
 					"Temporary DNS failure for '%s'.", domain);
 			// break;
 
 		case NO_RECOVERY:
 			if (spf_server->debug > 0)
-				SPF_debugf("get_record(%s): NO_RECOERY", domain);
+				SPF_debugf("get_record(%s): NO_RECOVERY", domain);
 			SPF_dns_rr_free(rr_txt);
+			if (rr_type == ns_t_spf) {
+				rr_type = ns_t_txt;
+				goto retry;
+			}
+			spf_response->result = SPF_RESULT_PERMERROR;
+			spf_response->reason = SPF_REASON_FAILURE;
 			return SPF_response_add_error(spf_response, SPF_E_DNS_ERROR,
 					"Unrecoverable DNS failure for '%s'.", domain);
 			// break;
@@ -405,6 +417,10 @@ retry:
 				SPF_debugf("get_record(%s): UNKNOWN_ERROR", domain);
 			herrno = rr_txt->herrno;	// Avoid use-after-free
 			SPF_dns_rr_free(rr_txt);
+			if (rr_type == ns_t_spf) {
+				rr_type = ns_t_txt;
+				goto retry;
+			}
 			return SPF_response_add_error(spf_response, SPF_E_DNS_ERROR,
 					"Unknown DNS failure for '%s': %d.",
 					domain, herrno);
