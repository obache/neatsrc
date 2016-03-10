$NetBSD$

* NetBSD-5 require too

--- ipv6.h.orig	2016-01-20 19:08:12.000000000 +0000
+++ ipv6.h
@@ -195,7 +195,7 @@ struct ipv6_state {
 	((const struct ipv6_state *)(ifp)->if_data[IF_DATA_IPV6])
 
 /* dhcpcd requires CMSG_SPACE to evaluate to a compile time constant. */
-#ifdef __QNX__
+#if defined(__QNX) || defined(__NetBSD_Version__) && __NetBSD_Version__ < 600000000
 #undef CMSG_SPACE
 #endif
 
