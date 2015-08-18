$NetBSD$

--- lib/misc/hostinfoPosix.c.orig	2015-06-17 16:14:30.000000000 +0000
+++ lib/misc/hostinfoPosix.c
@@ -40,7 +40,7 @@
 #include <sys/systeminfo.h>
 #endif
 #include <sys/socket.h>
-#if defined(__FreeBSD__) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__APPLE__) || defined(__NetBSD__)
 # include <sys/sysctl.h>
 #endif
 #if !defined(__APPLE__)
@@ -83,7 +83,7 @@
 #endif
 #endif
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #include <paths.h>
 #endif
 
@@ -284,7 +284,7 @@ HostinfoOSVersionInit(void)
     */
 
    p = extra;
-   while (*p && !isdigit(*p)) {
+   while (*p && !isdigit((int)*p)) {
       p++;
    }
    sscanf(p, "%d", &version->hostinfoOSVersion[3]);
@@ -420,7 +420,7 @@ Hostinfo_GetSystemBitness(void)
    }
 #else
    char buf[SYSTEM_BITNESS_MAXLEN] = { '\0', };
-#   if defined __FreeBSD__ || defined __APPLE__
+#   if defined __FreeBSD__ || defined __APPLE__ || defined __NetBSD__
    static int mib[2] = { CTL_HW, HW_MACHINE, };
    size_t len = sizeof buf;
 
@@ -1055,6 +1055,22 @@ HostinfoOSData(void)
       }
 
       Str_Strcpy(osName, STR_OS_FREEBSD, sizeof osName);
+   } else if (strstr(osNameFull, "NetBSD")) {
+      size_t nameLen = sizeof STR_OS_NETBSD - 1;
+      size_t releaseLen = 0;
+
+      /* NetBSD, as usual, just DTRT */
+      releaseLen = strlen(buf.release);
+
+      if (nameLen + releaseLen + 1 > sizeof osName) {
+         Warning("%s: Error: buffer too small\n", __FUNCTION__);
+
+         return FALSE;
+      }
+
+      Str_Strcpy(osName, STR_OS_NETBSD, sizeof osName);
+      Str_Snprintf(osName, sizeof osName, "%s%s", STR_OS_NETBSD,
+                   buf.release);
    } else if (strstr(osNameFull, "SunOS")) {
       size_t nameLen = sizeof STR_OS_SOLARIS - 1;
       size_t releaseLen = 0;
@@ -2435,8 +2451,8 @@ HostinfoGetCpuInfo(int nCpu,    // IN:
          e = s + strlen(s);
 
          /* Skip leading and trailing while spaces */
-         for (; s < e && isspace(*s); s++);
-         for (; s < e && isspace(e[-1]); e--);
+         for (; s < e && isspace((int)*s); s++);
+         for (; s < e && isspace((int)e[-1]); e--);
          *e = 0;
 
          /* Free previous value */
@@ -3279,7 +3295,7 @@ HostinfoSysinfo(uint64 *totalRam,  // OU
 #endif // ifndef __APPLE__
 
 
-#if defined(__linux__) || defined(__FreeBSD__) || defined(sun)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(sun) || defined(__NetBSD__)
 /*
  *-----------------------------------------------------------------------------
  *
