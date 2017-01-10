$NetBSD$

* for mem*

--- dvrecv/udp.c.orig	2008-03-12 10:28:07.000000000 +0000
+++ dvrecv/udp.c
@@ -43,6 +43,8 @@
 #include <sys/socket.h>
 #include <netinet/in.h>
 
+#include <string.h>
+
 #include <dvts.h>
 
 #include "param.h"
