$NetBSD$

--- src/objectc.c.orig	2016-10-30 05:05:19.000000000 +0000
+++ src/objectc.c
@@ -122,7 +122,7 @@ static void msgpack_object_bin_print(FIL
     for (i = 0; i < size; ++i) {
         if (ptr[i] == '"') {
             fputs("\\\"", out);
-        } else if (isprint(ptr[i])) {
+        } else if (isprint((unsigned char)ptr[i])) {
             fputc(ptr[i], out);
         } else {
             fprintf(out, "\\x%02x", (unsigned char)ptr[i]);
@@ -142,7 +142,7 @@ static int msgpack_object_bin_print_buff
             ret = snprintf(aux_buffer, aux_buffer_size, "\\\"");
             aux_buffer = aux_buffer + ret;
             aux_buffer_size = aux_buffer_size - ret;
-        } else if (isprint(ptr[i])) {
+        } else if (isprint((unsigned char)ptr[i])) {
             if (aux_buffer_size > 0) {
                 memcpy(aux_buffer, ptr + i, 1);
                 aux_buffer = aux_buffer + 1;
