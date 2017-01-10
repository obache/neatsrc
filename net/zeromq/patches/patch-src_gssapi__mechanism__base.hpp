$NetBSD$

* XXX mit-krb5 v.s. heimdal

--- src/gssapi_mechanism_base.hpp.orig	2015-11-04 08:55:13.000000000 +0000
+++ src/gssapi_mechanism_base.hpp
@@ -34,7 +34,7 @@
 
 #ifdef HAVE_LIBGSSAPI_KRB5
 
-#ifndef ZMQ_HAVE_FREEBSD
+#if !defined(ZMQ_HAVE_FREEBSD) && !defined(ZMQ_HAVE_DRAGONFLY) && !defined(ZMQ_HAVE_NETBSD)
 #include <gssapi/gssapi_generic.h>
 #endif
 #include <gssapi/gssapi_krb5.h>
