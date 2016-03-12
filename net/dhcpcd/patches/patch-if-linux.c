$NetBSD$

* Fix for missing O_CLOEXEC

--- if-linux.c.orig	2016-01-20 19:08:12.000000000 +0000
+++ if-linux.c
@@ -249,7 +249,7 @@ _open_link_socket(struct sockaddr_nl *nl
 {
 	int fd;
 
-	if ((fd = xsocket(AF_NETLINK, SOCK_RAW, protocol, O_CLOEXEC)) == -1)
+	if ((fd = xsocket(AF_NETLINK, SOCK_RAW, protocol, SOCK_CLOEXEC)) == -1)
 		return -1;
 	nl->nl_family = AF_NETLINK;
 	if (bind(fd, (struct sockaddr *)nl, sizeof(*nl)) == -1) {
@@ -1187,9 +1187,10 @@ if_openrawsocket(struct interface *ifp, 
 	int n;
 #endif
 
-	if ((s = xsocket(PF_PACKET, SOCK_DGRAM, htons(protocol),
-	    O_CLOEXEC | O_NONBLOCK)) == -1)
+#define SF	SOCK_CLOEXEC | SOCK_NONBLOCK
+	if ((s = xsocket(PF_PACKET, SOCK_DGRAM, htons(protocol), SF)) == -1)
 		return -1;
+#undef SF
 
 	/* Install the DHCP filter */
 	memset(&pf, 0, sizeof(pf));
