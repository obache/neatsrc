$NetBSD$

--- imap/mbexamine.c.orig	2015-05-08 03:49:52.000000000 +0000
+++ imap/mbexamine.c
@@ -264,7 +264,7 @@ static int do_examine(char *name,
     }
     printf("\n");
     printf("  Last POP3 Login: (%ld) %s", mailbox->i.pop3_last_login,
-	   ctime((const long *) &mailbox->i.pop3_last_login));
+	   ctime(&mailbox->i.pop3_last_login));
     printf("  Highest Mod Sequence: " MODSEQ_FMT "\n",
 	   mailbox->i.highestmodseq);
 
