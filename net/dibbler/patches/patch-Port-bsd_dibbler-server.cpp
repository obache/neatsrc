$NetBSD$

* stdlib.h is required for EXIT_SUCCESS and EXIT_FAILURE

--- Port-bsd/dibbler-server.cpp.orig	2015-07-29 22:07:38.000000000 +0000
+++ Port-bsd/dibbler-server.cpp
@@ -12,6 +12,7 @@
 
 #include <signal.h>
 #include <string.h>
+#include <stdlib.h>
 #include "DHCPServer.h"
 #include "Portable.h"
 #include "Logger.h"
