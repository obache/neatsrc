$NetBSD$

* declare `mailbox_meta_fname` also used by reconstruct.c

--- imap/mailbox.h.orig	2020-08-19 00:54:54.000000000 +0000
+++ imap/mailbox.h
@@ -402,6 +402,8 @@ typedef void mailbox_notifyproc_t(const 
 extern void mailbox_set_updatenotifier(mailbox_notifyproc_t *notifyproc);
 extern mailbox_notifyproc_t *mailbox_get_updatenotifier(void);
 
+extern void mailbox_make_uniqueid(struct mailbox *mailbox);
+
 /* file names on disk */
 #define META_FNAME_NEW 1
 extern char *mailbox_meta_fname(struct mailbox *mailbox, int metafile);
