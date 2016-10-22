$NetBSD$

* remove unused caldav headers

--- imap/ctl_cyrusdb.c.orig	2016-06-29 02:55:04.000000000 +0000
+++ imap/ctl_cyrusdb.c
@@ -71,8 +71,6 @@
 #endif
 
 #include "annotate.h"
-#include "caldav_alarm.h"
-#include "caldav_db.h"
 #include "cyrusdb.h"
 #include "duplicate.h"
 #include "global.h"
