$NetBSD$

* Tick is not a pointer

--- programs/dtcm/server/reprevtick.c.orig	2018-07-06 18:05:20.000000000 +0000
+++ programs/dtcm/server/reprevtick.c
@@ -92,7 +92,7 @@ PrevTick(
 	Tick 			 next_time;
 	Tick			 _start_time;
 
-        if (!re) return (Tick)NULL;
+        if (!re) return (Tick)0;
 
 	if (!start_time)
         	FillInRepeatEvent(cur_time, re);
@@ -148,7 +148,7 @@ DoMinute(
 	const RepeatEvent	*re,
 	RepeatEventState	*res)
 {
-	return (Tick)NULL;
+	return (Tick)0;
 }
 
 static Tick
