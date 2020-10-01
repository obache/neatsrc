$NetBSD$

--- dcop/dcopserver_shutdown.c.orig	2020-04-10 23:08:30.000000000 +0000
+++ dcop/dcopserver_shutdown.c
@@ -151,7 +151,7 @@ static void cleanupDCOPsocket(char *buff
    if (socket_file)
       unlink(socket_file);
 
-   snprintf(cmd, BUFFER_SIZE, "iceauth remove netid='%s'", buffer);
+   snprintf(cmd, BUFFER_SIZE, ICEAUTH_COMMAND " remove netid='%s'", buffer);
    system(cmd);
 }
 
