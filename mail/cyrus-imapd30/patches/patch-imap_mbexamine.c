$NetBSD$

--- imap/mbexamine.c.orig	2020-08-19 03:59:50.000000000 +0000
+++ imap/mbexamine.c
@@ -256,7 +256,7 @@ static int do_examine(struct findall_dat
     }
     printf("\n");
     printf("  Last POP3 Login: (%ld) %s", mailbox->i.pop3_last_login,
-           ctime((const long *) &mailbox->i.pop3_last_login));
+           ctime(&mailbox->i.pop3_last_login));
     printf("  Highest Mod Sequence: " MODSEQ_FMT "\n",
            mailbox->i.highestmodseq);
 
