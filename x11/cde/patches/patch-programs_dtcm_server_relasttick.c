$NetBSD$

* Tick is not a pointer

--- programs/dtcm/server/relasttick.c.orig	2018-07-06 18:05:20.000000000 +0000
+++ programs/dtcm/server/relasttick.c
@@ -63,7 +63,7 @@ LastTick(
 {
 	Tick 			 last_time;
 
-	if (!re) return (Tick)NULL;
+	if (!re) return (Tick)0;
 
 	if (re->re_duration == RE_INFINITY) return EOT;
 
@@ -101,7 +101,7 @@ DoMinute(
 	const Tick		 start_time,
 	const RepeatEvent	*re)
 {
-	return (Tick)NULL;
+	return (Tick)0;
 }
 
 static Tick
@@ -404,7 +404,7 @@ DoYearByMonth(
 			}
 		}
 		/* No months have a day that can be used */
-		return ((Tick)NULL); 
+		return ((Tick)0); 
 	}
 
 	last_time2 = mktime(start_tm);
