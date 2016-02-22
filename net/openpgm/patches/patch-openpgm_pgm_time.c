$NetBSD$

* NetBSD too

--- openpgm/pgm/time.c.orig	2012-12-04 02:57:22.000000000 +0000
+++ openpgm/pgm/time.c
@@ -163,7 +163,7 @@ static pgm_time_t		pgm_rtc_update (void)
 #ifdef HAVE_RDTSC
 #	include <stdio.h>
 #	include <string.h>
-#	if defined(__APPLE__) || defined(__FreeBSD__)
+#	if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #		include <sys/sysctl.h>
 #	elif defined(__sun)
 #		include <kstat.h>
@@ -449,6 +449,13 @@ pgm_time_init (
 		if (0 == sysctlbyname ("hw.clockrate", &clockrate, &len, NULL, 0)) {
 			tsc_khz = (uint_fast32_t)(clockrate * 1000);
 		}
+#elif defined(__NetBSD__)
+		uint64_t clockrate;
+		size_t len;
+		len = sizeof (clockrate);
+		if (0 == sysctlbyname ("machdep.tsc_freq", &clockrate, &len, NULL, 0)) {
+			tsc_khz = (uint_fast32_t)(clockrate / 1000);
+		}
 #elif defined(KSTAT_DATA_INT32)
 /* ref: http://developers.sun.com/solaris/articles/kstatc.html */
 		kstat_ctl_t* kc;
