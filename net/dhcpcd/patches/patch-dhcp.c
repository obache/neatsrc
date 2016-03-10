$NetBSD$

* Fix for missing O_CLOEXEC

--- dhcp.c.orig	2016-01-20 19:08:12.000000000 +0000
+++ dhcp.c
@@ -1489,7 +1489,7 @@ dhcp_openudp(struct interface *ifp)
 	char *p;
 #endif
 
-	if ((s = xsocket(PF_INET, SOCK_DGRAM, IPPROTO_UDP, O_CLOEXEC)) == -1)
+	if ((s = xsocket(PF_INET, SOCK_DGRAM, IPPROTO_UDP, SOCK_CLOEXEC)) == -1)
 		return -1;
 
 	n = 1;
