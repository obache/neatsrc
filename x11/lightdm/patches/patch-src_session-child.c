$NetBSD$

* GNU-ish

--- src/session-child.c.orig	2015-11-02 03:25:10.000000000 +0000
+++ src/session-child.c
@@ -202,6 +202,7 @@ read_xauth (void)
     return x_authority_new (x_authority_family, x_authority_address, x_authority_address_length, x_authority_number, x_authority_name, x_authority_data, x_authority_data_length);
 }
 
+#ifdef __GLIBC__
 /* GNU provides this but we can't rely on that so let's make our own version */
 static void
 updwtmpx (const gchar *wtmp_file, struct utmpx *ut)
@@ -224,6 +225,7 @@ updwtmpx (const gchar *wtmp_file, struct
 
     updwtmp (wtmp_file, &u);
 }
+#endif
 
 #if HAVE_LIBAUDIT
 static void
