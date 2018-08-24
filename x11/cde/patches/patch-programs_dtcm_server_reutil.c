$NetBSD$

* Tick is not a pointer

--- programs/dtcm/server/reutil.c.orig	2018-07-06 18:05:20.000000000 +0000
+++ programs/dtcm/server/reutil.c
@@ -230,7 +230,7 @@ WeekNumberToDay(
          * month.
          */
         if (date_tm->tm_mon != initial_month_number)
-                return ((Tick)NULL);
+                return ((Tick)0);
 
         return (_date);
 }
