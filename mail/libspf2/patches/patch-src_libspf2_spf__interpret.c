$NetBSD$

* from upstream fix

--- src/libspf2/spf_interpret.c.orig	2012-01-28 08:24:47.000000000 +0000
+++ src/libspf2/spf_interpret.c
@@ -104,7 +104,6 @@ SPF_i_set_smtp_comment(SPF_response_t *s
 		case SPF_RESULT_FAIL:
 		case SPF_RESULT_SOFTFAIL:
 		case SPF_RESULT_NEUTRAL:
-		case SPF_RESULT_NONE:
 
 			err = SPF_i_set_explanation(spf_response);
 			if (err != SPF_E_SUCCESS)
@@ -126,6 +125,7 @@ SPF_i_set_smtp_comment(SPF_response_t *s
 		case SPF_RESULT_PASS:
 		case SPF_RESULT_TEMPERROR:
 		case SPF_RESULT_PERMERROR:
+		case SPF_RESULT_NONE:
 		default:
 			break;
 	}
