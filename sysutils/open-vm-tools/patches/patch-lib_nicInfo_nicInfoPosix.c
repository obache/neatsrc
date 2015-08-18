$NetBSD$

--- lib/nicInfo/nicInfoPosix.c.orig	2015-06-17 16:14:30.000000000 +0000
+++ lib/nicInfo/nicInfoPosix.c
@@ -34,7 +34,7 @@
 #include <sys/socket.h>
 #include <sys/stat.h>
 #include <errno.h>
-#if defined(__FreeBSD__) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__APPLE__) || defined(__NetBSD__)
 # include <sys/sysctl.h>
 # include <ifaddrs.h>
 # include <net/if.h>
@@ -62,6 +62,12 @@
 #   include <net/if.h>
 #endif
 
+#if defined(__NetBSD__)
+static struct __res_state res;
+#else
+#  define res (&_res)
+#endif
+
 /*
  * resolver(3) and IPv6:
  *
@@ -137,7 +143,7 @@ static int ReadInterfaceDetails(const st
 static Bool RecordResolverInfo(NicInfoV3 *nicInfo);
 static void RecordResolverNS(DnsConfigInfo *dnsConfigInfo);
 static Bool RecordRoutingInfo(NicInfoV3 *nicInfo);
-#if !defined(__FreeBSD__) && !defined(__APPLE__) && !defined(USERWORLD)
+#if !defined(__FreeBSD__) && !defined(__APPLE__) && !defined(__NetBSD__) && !defined(USERWORLD)
 static int GuestInfoGetIntf(const struct intf_entry *entry, void *arg);
 #endif
 #endif
@@ -280,7 +286,7 @@ GuestInfoGetNicInfo(NicInfoV3 *nicInfo) 
  *
  ******************************************************************************
  */
-#if defined(__FreeBSD__) || defined(__APPLE__) || defined(USERWORLD)
+#if defined(__FreeBSD__) || defined(__APPLE__) || defined(__NetBSD__) || defined(USERWORLD)
 
 char *
 GuestInfoGetPrimaryIP(void)
@@ -470,8 +476,12 @@ RecordResolverInfo(NicInfoV3 *nicInfo)  
    DnsConfigInfo *dnsConfigInfo = NULL;
    char namebuf[DNSINFO_MAX_ADDRLEN + 1];
    char **s;
-
+#if defined(__NetBSD__)
+   memset(&res, 0, sizeof(res));
+   if (res_ninit(&res) == -1) {
+#else
    if (res_init() == -1) {
+#endif
       return FALSE;
    }
 
@@ -492,7 +502,7 @@ RecordResolverInfo(NicInfoV3 *nicInfo)  
     */
    dnsConfigInfo->domainName =
       Util_SafeCalloc(1, sizeof *dnsConfigInfo->domainName);
-   *dnsConfigInfo->domainName = Util_SafeStrdup(_res.defdname);
+   *dnsConfigInfo->domainName = Util_SafeStrdup(res.defdname);
 
    /*
     * Name servers.
@@ -502,7 +512,7 @@ RecordResolverInfo(NicInfoV3 *nicInfo)  
    /*
     * Search suffixes.
     */
-   for (s = _res.dnsrch; *s; s++) {
+   for (s = res.dnsrch; *s; s++) {
       DnsHostname *suffix;
 
       /* Check to see if we're going above our limit. See bug 605821. */
@@ -550,12 +560,12 @@ RecordResolverNS(DnsConfigInfo *dnsConfi
 #if defined RESOLVER_IPV6_GETSERVERS
    {
       union res_sockaddr_union *ns;
-      ns = Util_SafeCalloc(_res.nscount, sizeof *ns);
-      if (res_getservers(&_res, ns, _res.nscount) != _res.nscount) {
+      ns = Util_SafeCalloc(res.nscount, sizeof *ns);
+      if (res_getservers(&res, ns, res.nscount) != res.nscount) {
          g_warning("%s: res_getservers failed.\n", __func__);
          return;
       }
-      for (i = 0; i < _res.nscount; i++) {
+      for (i = 0; i < res.nscount; i++) {
          struct sockaddr *sa = (struct sockaddr *)&ns[i];
          if (sa->sa_family == AF_INET || sa->sa_family == AF_INET6) {
             TypedIpAddress *ip;
@@ -847,7 +857,7 @@ RecordRoutingInfo(NicInfoV3 *nicInfo)
 }
 #endif                                          // else
 
-#if !defined(__FreeBSD__) && !defined(__APPLE__) && !defined(USERWORLD)
+#if !defined(__FreeBSD__) && !defined(__APPLE__) && !defined(__NetBSD__) && !defined(USERWORLD)
 /*
  ******************************************************************************
  * GuestInfoGetIntf --                                                   */ /**
