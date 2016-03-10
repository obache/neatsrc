$NetBSD$

* Fix for missing O_CLOEXEC

--- if-bsd.c.orig	2016-01-20 19:08:12.000000000 +0000
+++ if-bsd.c
@@ -124,7 +124,7 @@ int
 if_openlinksocket(void)
 {
 
-	return xsocket(PF_ROUTE, SOCK_RAW, 0, O_NONBLOCK|O_CLOEXEC);
+	return xsocket(PF_ROUTE, SOCK_RAW, 0, SOCK_NONBLOCK|SOCK_CLOEXEC);
 }
 
 #if defined(INET) || defined(INET6)
@@ -291,21 +291,40 @@ if_openrawsocket(struct interface *ifp, 
 #ifdef BIOCIMMEDIATE
 	int flags;
 #endif
+#ifndef O_CLOEXEC
+	int fd_opts;
+#endif
+
 #ifdef _PATH_BPF
-	fd = open(_PATH_BPF, O_RDWR | O_CLOEXEC | O_NONBLOCK);
+	fd = open(_PATH_BPF, O_RDWR | O_NONBLOCK
+#ifdef O_CLOEXEC
+		| O_CLOEXEC
+#endif
+	);
 #else
 	char device[32];
 	int n = 0;
 
 	do {
 		snprintf(device, sizeof(device), "/dev/bpf%d", n++);
-		fd = open(device, O_RDWR | O_CLOEXEC | O_NONBLOCK);
+		fd = open(device, O_RDWR | O_NONBLOCK
+#ifdef O_CLOEXEC
+				| O_CLOEXEC
+#endif
+		);
 	} while (fd == -1 && errno == EBUSY);
 #endif
 
 	if (fd == -1)
 		return -1;
 
+#ifndef O_CLOEXEC
+	if ((fd_opts = fcntl(fd, F_GETFD)) == -1 ||
+	    fcntl(fd, F_SETFD, fd_opts | FD_CLOEXEC) == -1) {
+		close(fd);
+		return -1;
+	}
+#endif
 	state = IPV4_STATE(ifp);
 	memset(&pv, 0, sizeof(pv));
 	if (ioctl(fd, BIOCVERSION, &pv) == -1)
