$NetBSD$

--- lib/csa/cmxdr.c.orig	2015-05-09 23:09:11.000000000 +0000
+++ lib/csa/cmxdr.c
@@ -47,6 +47,16 @@ xdr_time_t(register XDR *xdrs, time_t *o
 #ifdef __osf__
 	if (!xdr_int(xdrs, objp))
 		return (FALSE);
+#elif defined(__NetBSD__)
+	if (sizeof(time_t) == sizeof(long)) {
+		if (!xdr_long(xdrs, objp))
+			return (FALSE);
+	} else if (sizeof(time_t) == sizeof(longlong_t)) {
+		if (!xdr_longlong_t(xdrs, objp))
+			return (FALSE);
+	} else {
+		return FALSE;
+	}
 #else
 	if (!xdr_long(xdrs, objp))
 		return (FALSE);
