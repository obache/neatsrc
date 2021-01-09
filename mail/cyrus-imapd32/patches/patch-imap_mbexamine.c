$NetBSD$

--- imap/mbexamine.c.orig	2020-11-29 23:52:47.000000000 +0000
+++ imap/mbexamine.c
@@ -256,7 +256,7 @@ static int do_examine(struct findall_dat
     }
     printf("\n");
     printf("  Last POP3 Login: (" TIME_T_FMT ") %s", mailbox->i.pop3_last_login,
-           ctime((const time_t *) &mailbox->i.pop3_last_login));
+           ctime(&mailbox->i.pop3_last_login));
     printf("  Highest Mod Sequence: " MODSEQ_FMT "\n",
            mailbox->i.highestmodseq);
 
