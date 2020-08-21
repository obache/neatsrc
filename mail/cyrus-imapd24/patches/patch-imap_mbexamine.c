$NetBSD$

* cast to unsigned long for platform sizeof(time_t) > sizeof(unsigned long)

--- imap/mbexamine.c.orig	2020-08-19 00:54:54.000000000 +0000
+++ imap/mbexamine.c
@@ -262,8 +262,8 @@ int do_examine(char *name,
 	   mailbox->i.start_offset, mailbox->i.record_size);
     printf("  Number of Messages: %u  Mailbox Size: " UQUOTA_T_FMT " bytes\n",
 	   mailbox->i.exists, mailbox->i.quota_mailbox_used);
-    printf("  Last Append Date: (%lu) %s",
-	   mailbox->i.last_appenddate, ctime(&mailbox->i.last_appenddate));
+    printf("  Last Append Date: (" MODSEQ_FMT ") %s",
+	   (modseq_t)mailbox->i.last_appenddate, ctime(&mailbox->i.last_appenddate));
     printf("  UIDValidity: %u  Last UID: %u\n",
 	   mailbox->i.uidvalidity, mailbox->i.last_uid);
     printf("  Deleted: %u  Answered: %u  Flagged: %u\n",
@@ -283,8 +283,8 @@ int do_examine(char *name,
 	}
     }
     printf("\n");
-    printf("  Last POP3 Login: (%ld) %s", mailbox->i.pop3_last_login,
-	   ctime((const long *) &mailbox->i.pop3_last_login));
+    printf("  Last POP3 Login: (" MODSEQ_FMT ") %s", (modseq_t)mailbox->i.pop3_last_login,
+	   ctime(&mailbox->i.pop3_last_login));
     printf("  Highest Mod Sequence: " MODSEQ_FMT "\n",
 	   mailbox->i.highestmodseq);
 
@@ -307,11 +307,11 @@ int do_examine(char *name,
 	    flag = 1;
 	}
 
-	printf("%06u> UID:%08u   INT_DATE:%lu SENTDATE:%lu SIZE:%-6u\n",
-	       msgno, record.uid, record.internaldate,
-	       record.sentdate, record.size);
-	printf("      > HDRSIZE:%-6u LASTUPD :%lu SYSFLAGS:%08X",
-	       record.header_size, record.last_updated,
+	printf("%06u> UID:%08u   INT_DATE:" MODSEQ_FMT " SENTDATE:" MODSEQ_FMT " SIZE:%-6u\n",
+	       msgno, record.uid, (modseq_t)record.internaldate,
+	       (modseq_t)record.sentdate, record.size);
+	printf("      > HDRSIZE:%-6u LASTUPD :" MODSEQ_FMT " SYSFLAGS:%08X",
+	       record.header_size, (modseq_t)record.last_updated,
 	       record.system_flags);
 	if (mailbox->i.minor_version >= 5)
 	    printf("   LINES:%-6u\n", record.content_lines);
