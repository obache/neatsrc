$NetBSD$

* cast to unsigned long for platform sizeof(time_t) > sizeof(unsigned long)

--- imap/mbexamine.c.orig	2020-08-19 01:37:51.000000000 +0000
+++ imap/mbexamine.c
@@ -242,8 +242,8 @@ static int do_examine(char *name,
 	   mailbox->i.start_offset, mailbox->i.record_size);
     printf("  Number of Messages: %u  Mailbox Size: " QUOTA_T_FMT " bytes  Annotations Size: " QUOTA_T_FMT " bytes\n",
 	   mailbox->i.exists, mailbox->i.quota_mailbox_used, mailbox->i.quota_annot_used);
-    printf("  Last Append Date: (%lu) %s",
-	   mailbox->i.last_appenddate, ctime(&mailbox->i.last_appenddate));
+    printf("  Last Append Date: (" MODSEQ_FMT ") %s",
+	   (modseq_t)mailbox->i.last_appenddate, ctime(&mailbox->i.last_appenddate));
     printf("  UIDValidity: %u  Last UID: %u\n",
 	   mailbox->i.uidvalidity, mailbox->i.last_uid);
     printf("  Deleted: %u  Answered: %u  Flagged: %u\n",
@@ -263,8 +263,8 @@ static int do_examine(char *name,
 	}
     }
     printf("\n");
-    printf("  Last POP3 Login: (%ld) %s", mailbox->i.pop3_last_login,
-	   ctime((const long *) &mailbox->i.pop3_last_login));
+    printf("  Last POP3 Login: (" MODSEQ_FMT ") %s", (modseq_t)mailbox->i.pop3_last_login,
+	   ctime(&mailbox->i.pop3_last_login));
     printf("  Highest Mod Sequence: " MODSEQ_FMT "\n",
 	   mailbox->i.highestmodseq);
 
