$NetBSD$

* time_t should be used for time

--- pmlist.h.orig	2006-10-01 15:58:32.000000000 +0000
+++ pmlist.h
@@ -23,7 +23,7 @@ struct portMap
   char m_PortMappingDescription[50];
 
   int expirationEventId;
-  long int expirationTime;
+  time_t expirationTime;
 
   struct portMap* next;
   struct portMap* prev;
