$NetBSD$

--- imap/ctl_zoneinfo.c.orig	2015-09-11 01:18:38.000000000 +0000
+++ imap/ctl_zoneinfo.c
@@ -236,7 +236,7 @@ void do_zonedir(const char *dir, struct 
 	    /* Path is a regular file (zone) */
 	    int fd;
 	    const char *base = NULL;
-	    unsigned long len = 0;
+	    size_t len = 0;
 	    icalcomponent *ical, *comp;
 	    icalproperty *prop;
 
