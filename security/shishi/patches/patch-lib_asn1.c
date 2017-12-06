$NetBSD$

* for size_t != int

--- lib/asn1.c.orig	2013-04-02 23:14:34.000000000 +0000
+++ lib/asn1.c
@@ -124,8 +124,11 @@ shishi_asn1_read_inline (Shishi * handle
 			 const char *field, char *data, size_t * datalen)
 {
   int rc;
+  int data_len;
 
-  rc = asn1_read_value (node, field, (unsigned char *) data, (int *) datalen);
+  data_len = (int) *datalen;
+  rc = asn1_read_value (node, field, (unsigned char *) data, &data_len);
+  *datalen = data_len;
   if (rc != ASN1_SUCCESS)
     {
       shishi_error_set (handle, asn1_strerror (rc));
