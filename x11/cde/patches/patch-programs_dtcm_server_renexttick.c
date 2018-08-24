$NetBSD$

* Tick is not a pointer

--- programs/dtcm/server/renexttick.c.orig	2018-07-06 18:05:20.000000000 +0000
+++ programs/dtcm/server/renexttick.c
@@ -79,7 +79,7 @@ NextTick(
 {
 	Tick 			 next_time;
 
-	if (!re) return (Tick)NULL;
+	if (!re) return (Tick)0;
 
 	FillInRepeatEvent(start_time, re);
 
@@ -126,7 +126,7 @@ DoMinute(
 	const RepeatEvent	*re,
 	RepeatEventState	*res)
 {
-	return (Tick)NULL;
+	return (Tick)0;
 }
 
 static Tick
