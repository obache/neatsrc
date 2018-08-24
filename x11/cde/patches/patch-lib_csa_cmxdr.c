$NetBSD$

--- lib/csa/cmxdr.c.orig	2018-07-06 18:05:20.000000000 +0000
+++ lib/csa/cmxdr.c
@@ -44,8 +44,20 @@
 bool_t
 xdr_time_t(register XDR *xdrs, time_t *objp)
 {
+#if defined(__NetBSD__)
+	if (sizeof(time_t) == sizeof(long)) {
+		if (!xdr_long(xdrs, objp))
+			return (FALSE);
+	} else if (sizeof(time_t) == sizeof(longlong_t)) {
+		if (!xdr_longlong_t(xdrs, objp))
+			return (FALSE);
+	} else {
+		return FALSE;
+	}
+#else
 	if (!xdr_long(xdrs, objp))
 		return (FALSE);
+#endif
 	return (TRUE);
 }
  
