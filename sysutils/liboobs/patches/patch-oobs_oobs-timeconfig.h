$NetBSD$

* for time_t != long

--- oobs/oobs-timeconfig.h.orig	2010-04-13 10:51:59.000000000 +0000
+++ oobs/oobs-timeconfig.h
@@ -59,8 +59,8 @@ GType       oobs_time_config_get_type   
 
 OobsObject* oobs_time_config_get           (void);
 
-glong       oobs_time_config_get_unix_time (OobsTimeConfig *config);
-void        oobs_time_config_set_unix_time (OobsTimeConfig *config, glong unix_time);
+time_t      oobs_time_config_get_unix_time (OobsTimeConfig *config);
+void        oobs_time_config_set_unix_time (OobsTimeConfig *config, time_t unix_time);
 
 void        oobs_time_config_get_time      (OobsTimeConfig *config, gint *year, gint *month, gint *day, gint *hour, gint *minute, gint *second);
 void        oobs_time_config_set_time      (OobsTimeConfig *config, gint  year, gint  month, gint  day, gint  hour, gint  minute, gint  second);
