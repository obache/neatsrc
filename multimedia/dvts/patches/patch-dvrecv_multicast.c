$NetBSD$

* for mem*

--- dvrecv/multicast.c.orig	2008-03-12 10:28:07.000000000 +0000
+++ dvrecv/multicast.c
@@ -46,6 +46,8 @@
 #include <net/if.h>
 #include <arpa/inet.h>
 
+#include <string.h>
+
 #include <dvts.h>
 
 #include "multicast.h"
