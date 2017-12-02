$NetBSD$

* from upstream fix

--- src/libspf2/spf_dns_cache.c.orig	2012-01-28 08:24:47.000000000 +0000
+++ src/libspf2/spf_dns_cache.c
@@ -342,7 +342,7 @@ SPF_dns_cache_rr_fixup(SPF_dns_cache_con
 		cached_rr->ttl = spfhook->min_ttl;
 
     if ( cached_rr->ttl < spfhook->txt_ttl
-			&& cached_rr->rr_type == ns_t_txt )
+			&& (cached_rr->rr_type == ns_t_txt || cached_rr->rr_type== ns_t_spf))
 		cached_rr->ttl = spfhook->txt_ttl;
 
     if ( cached_rr->ttl < spfhook->err_ttl
