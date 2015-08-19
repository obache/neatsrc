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
@@ -135,9 +135,9 @@
 static void RecordNetworkAddress(GuestNicV3 *nic, const struct addr *addr);
 static int ReadInterfaceDetails(const struct intf_entry *entry, void *arg);
 static Bool RecordResolverInfo(NicInfoV3 *nicInfo);
-static void RecordResolverNS(DnsConfigInfo *dnsConfigInfo);
+static void RecordResolverNS(DnsConfigInfo *dnsConfigInfo, res_state res);
 static Bool RecordRoutingInfo(NicInfoV3 *nicInfo);
-#if !defined(__FreeBSD__) && !defined(__APPLE__) && !defined(USERWORLD)
+#if !defined(__FreeBSD__) && !defined(__APPLE__) && !defined(__NetBSD__) && !defined(USERWORLD)
 static int GuestInfoGetIntf(const struct intf_entry *entry, void *arg);
 #endif
 #endif
@@ -280,7 +280,7 @@ GuestInfoGetNicInfo(NicInfoV3 *nicInfo) 
  *
  ******************************************************************************
  */
-#if defined(__FreeBSD__) || defined(__APPLE__) || defined(USERWORLD)
+#if defined(__FreeBSD__) || defined(__APPLE__) || defined(__NetBSD__) || defined(USERWORLD)
 
 char *
 GuestInfoGetPrimaryIP(void)
@@ -471,7 +471,14 @@ RecordResolverInfo(NicInfoV3 *nicInfo)  
    char namebuf[DNSINFO_MAX_ADDRLEN + 1];
    char **s;
 
+#if defined(__NetBSD__)
+   res_state res;
+   res = __res_get_state();
+   if (res == NULL) {
+#else
+#  define res (&_res)
    if (res_init() == -1) {
+#endif
       return FALSE;
    }
 
@@ -492,17 +499,17 @@ RecordResolverInfo(NicInfoV3 *nicInfo)  
     */
    dnsConfigInfo->domainName =
       Util_SafeCalloc(1, sizeof *dnsConfigInfo->domainName);
-   *dnsConfigInfo->domainName = Util_SafeStrdup(_res.defdname);
+   *dnsConfigInfo->domainName = Util_SafeStrdup(res->defdname);
 
    /*
     * Name servers.
     */
-   RecordResolverNS(dnsConfigInfo);
+   RecordResolverNS(dnsConfigInfo, res);
 
    /*
     * Search suffixes.
     */
-   for (s = _res.dnsrch; *s; s++) {
+   for (s = res->dnsrch; *s; s++) {
       DnsHostname *suffix;
 
       /* Check to see if we're going above our limit. See bug 605821. */
@@ -543,19 +550,19 @@ fail:
  */
 
 static void
-RecordResolverNS(DnsConfigInfo *dnsConfigInfo) // IN
+RecordResolverNS(DnsConfigInfo *dnsConfigInfo, res_state res) // IN
 {
    int i;
 
 #if defined RESOLVER_IPV6_GETSERVERS
    {
       union res_sockaddr_union *ns;
-      ns = Util_SafeCalloc(_res.nscount, sizeof *ns);
-      if (res_getservers(&_res, ns, _res.nscount) != _res.nscount) {
+      ns = Util_SafeCalloc(res->nscount, sizeof *ns);
+      if (res_getservers(res, ns, res->nscount) != res->nscount) {
          g_warning("%s: res_getservers failed.\n", __func__);
          return;
       }
-      for (i = 0; i < _res.nscount; i++) {
+      for (i = 0; i < res->nscount; i++) {
          struct sockaddr *sa = (struct sockaddr *)&ns[i];
          if (sa->sa_family == AF_INET || sa->sa_family == AF_INET6) {
             TypedIpAddress *ip;
@@ -847,7 +854,7 @@ RecordRoutingInfo(NicInfoV3 *nicInfo)
 }
 #endif                                          // else
 
-#if !defined(__FreeBSD__) && !defined(__APPLE__) && !defined(USERWORLD)
+#if !defined(__FreeBSD__) && !defined(__APPLE__) && !defined(__NetBSD__) && !defined(USERWORLD)
 /*
  ******************************************************************************
  * GuestInfoGetIntf --                                                   */ /**
