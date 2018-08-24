$NetBSD$

* Tick is not a pointer

--- programs/dtcm/server/reclotick.c.orig	2018-07-06 18:05:20.000000000 +0000
+++ programs/dtcm/server/reclotick.c
@@ -81,12 +81,12 @@ ClosestTick(
 				 real_start_time,
 				 target_time = _target_time;
 
-	if (!re) return (Tick)NULL;
+	if (!re) return (Tick)0;
 
 	FillInRepeatEvent(start_time, re);
 
 	if (!(*res = InitRepeatEventState(re)))
-		return (Tick)NULL;
+		return (Tick)0;
 
 	if (target_time < start_time)
 		target_time = start_time;
@@ -131,7 +131,7 @@ ClosestTick(
 	    (re->re_end_date && re->re_end_date < closest_tick)) { 
 		free (*res);
 		*res = NULL;
-		return (Tick)NULL;
+		return (Tick)0;
 	}
 
 	/*
@@ -351,7 +351,7 @@ DoWeek(
 	/* Make sure the start time is on the first real event slot. */
 	if (_target_time) {
 		if (!(unused = InitRepeatEventState(re)))
-			return (Tick)NULL;
+			return (Tick)0;
 		start_time = DoWeek(0, _start_time, re, unused);
 		free(unused);
 		if (_target_time < start_time)
@@ -676,7 +676,7 @@ DoYearByMonth(
 	/* Make sure the start time is on the first real event slot. */
 	if (_target_time) {
 		if (!(unused = InitRepeatEventState(re)))
-			return (Tick)NULL;
+			return (Tick)0;
 		start_time = DoYearByMonth(0, _start_time, re, unused);
 		free(unused);
 		if (_target_time < start_time)
@@ -780,7 +780,7 @@ DoYearByDay(
 	/* Make sure the start time is on the first real event slot. */
 	if (_target_time) {
 		if (!(unused = InitRepeatEventState(re)))
-			return (Tick)NULL;
+			return (Tick)0;
 		start_time = DoYearByDay(0, _start_time, re, unused);
 		free(unused);
 		if (_target_time < start_time)
