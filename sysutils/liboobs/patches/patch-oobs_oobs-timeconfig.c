$NetBSD$

* for time_t != long

--- oobs/oobs-timeconfig.c.orig	2010-02-15 14:36:06.000000000 +0000
+++ oobs/oobs-timeconfig.c
@@ -328,10 +328,10 @@ date_is_sane (gint year,
  * 
  * Return Value: The unix time of the system.
  **/
-glong
+time_t
 oobs_time_config_get_unix_time (OobsTimeConfig *config)
 {
-  glong unix_time;
+  time_t unix_time;
 
   g_return_val_if_fail (OOBS_IS_TIME_CONFIG (config), 0);
 
@@ -349,7 +349,7 @@ oobs_time_config_get_unix_time (OobsTime
  * is measured in seconds, since the "epoch" (1970-01-01T00:00:00Z).
  **/
 void
-oobs_time_config_set_unix_time (OobsTimeConfig *config, glong unix_time)
+oobs_time_config_set_unix_time (OobsTimeConfig *config,time_t unix_time)
 {
   g_return_if_fail (OOBS_IS_TIME_CONFIG (config));
 
@@ -366,7 +366,7 @@ real_get_time (OobsTimeConfig *config,
 	       gint           *minute,
 	       gint           *second)
 {
-  glong unix_time;
+  time_t unix_time;
   struct tm *tm;
 
   g_return_if_fail (OOBS_IS_TIME_CONFIG (config));
@@ -450,11 +450,11 @@ oobs_time_config_get_utc_time (OobsTimeC
 		 hour, minute, second);
 }
 
-static glong
+static time_t
 get_utc_unix_time (struct tm *tm)
 {
   gchar *tz;
-  glong unix_time;
+  time_t unix_time;
 
   tz = getenv ("TZ");
   setenv ("TZ", "", 1);
@@ -483,7 +483,7 @@ real_set_time (OobsTimeConfig *config,
 	       gint            second)
 {
   struct tm tm = { 0, };
-  glong unix_time;
+  time_t unix_time;
 
   g_return_if_fail (OOBS_IS_TIME_CONFIG (config));
   g_return_if_fail (date_is_sane (year, month, day, hour, minute, second));
