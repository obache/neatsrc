$NetBSD: patch-src_tcp__address.cpp,v 1.1 2015/09/30 10:45:10 fhajny Exp $

Back port build fix for SunOS.
From https://github.com/zeromq/libzmq/pull/1440

--- src/tcp_address.cpp.orig	2015-12-18 08:21:09.000000000 +0000
+++ src/tcp_address.cpp
@@ -86,7 +86,7 @@ int zmq::tcp_address_t::resolve_nic_name
     //  Find the interface with the specified name and AF_INET family.
     bool found = false;
     lifreq *ifrp = ifc.lifc_req;
-    for (int n = 0; n < (int) (ifc.lifc_len / sizeof lifreq);
+    for (int n = 0; n < (int) (ifc.lifc_len / sizeof (lifreq));
           n ++, ifrp ++) {
         if (!strcmp (nic_, ifrp->lifr_name)) {
             rc = ioctl (fd, SIOCGLIFADDR, (char*) ifrp);
@@ -156,7 +156,8 @@ int zmq::tcp_address_t::resolve_nic_name
 
 #elif ((defined ZMQ_HAVE_LINUX || defined ZMQ_HAVE_FREEBSD ||\
     defined ZMQ_HAVE_OSX || defined ZMQ_HAVE_OPENBSD ||\
-    defined ZMQ_HAVE_QNXNTO || defined ZMQ_HAVE_NETBSD)\
+    defined ZMQ_HAVE_QNXNTO || defined ZMQ_HAVE_NETBSD ||\
+    defined ZMQ_HAVE_DRAGONFLY)\
     && defined ZMQ_HAVE_IFADDRS)
 
 #include <ifaddrs.h>
@@ -281,7 +282,7 @@ int zmq::tcp_address_t::resolve_interfac
     //  service-name irregularity due to indeterminate socktype.
     req.ai_flags = AI_PASSIVE | AI_NUMERICHOST;
 
-#if defined AI_V4MAPPED && !defined ZMQ_HAVE_FREEBSD
+#if defined AI_V4MAPPED && !defined ZMQ_HAVE_FREEBSD && !defined ZMQ_HAVE_DRAGONFLY
     //  In this API we only require IPv4-mapped addresses when
     //  no native IPv6 interfaces are available (~AI_ALL).
     //  This saves an additional DNS roundtrip for IPv4 addresses.
@@ -331,7 +332,7 @@ int zmq::tcp_address_t::resolve_hostname
     //  doesn't really matter, since it's not included in the addr-output.
     req.ai_socktype = SOCK_STREAM;
 
-#if defined AI_V4MAPPED && !defined ZMQ_HAVE_FREEBSD
+#if defined AI_V4MAPPED && !defined ZMQ_HAVE_FREEBSD && !defined ZMQ_HAVE_DRAGONFLY
     //  In this API we only require IPv4-mapped addresses when
     //  no native IPv6 interfaces are available.
     //  This saves an additional DNS roundtrip for IPv4 addresses.
