$NetBSD$

* cast to unsigned long for platform sizeof(time_t) > sizeof(unsigned long).
  https://bugzilla.cyrusimap.org/show_bug.cgi?id=3376

--- imap/mailbox.c.orig	2015-03-03 12:09:17.000000000 +0000
+++ imap/mailbox.c
@@ -2234,10 +2234,10 @@ static uint32_t crc_basic(const struct m
 	flagcrc ^= crc32_cstring(buf);
     }
 
-    snprintf(buf, sizeof(buf), "%u " MODSEQ_FMT " %lu (%u) %lu %s",
-	    record->uid, record->modseq, record->last_updated,
+    snprintf(buf, sizeof(buf), "%u " MODSEQ_FMT " " MODSEQ_FMT " (%u) " MODSEQ_FMT " %s",
+	    record->uid, record->modseq, (modseq_t)record->last_updated,
 	    flagcrc,
-	    record->internaldate,
+	    (modseq_t)record->internaldate,
 	    message_guid_encode(&record->guid));
 
     return crc32_cstring(buf);
