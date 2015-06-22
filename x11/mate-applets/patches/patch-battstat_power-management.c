$NetBSD$

* NetBSD support

--- battstat/power-management.c.orig	2015-01-22 09:16:53.000000000 +0000
+++ battstat/power-management.c
@@ -239,7 +239,11 @@ apm_readinfo (BatteryStatus *status)
 #elif defined(__NetBSD__) || defined(__OpenBSD__)
 
 #include <sys/param.h>
+#if defined(__NetBSD__)
+#include <dev/apm/apmio.h>
+#else /* __OpenBSD__ */
 #include <machine/apmvar.h>
+#endif
 
 #define APMDEVICE "/dev/apm"
 
@@ -249,7 +253,11 @@ apm_readinfo (BatteryStatus *status)
   /* Code for OpenBSD by Joe Ammond <jra@twinight.org>. Using the same
      procedure as for FreeBSD.
   */
+#if defined(__NetBSD__)
+  struct apm_power_info apminfo;
+#else /* __OpenBSD__ */
   struct apm_info apminfo;
+#endif
   int fd;
 
 #if defined(__NetBSD__)
