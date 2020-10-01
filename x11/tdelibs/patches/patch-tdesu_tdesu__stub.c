$NetBSD$

--- tdesu/tdesu_stub.c.orig	2020-04-10 23:08:30.000000000 +0000
+++ tdesu/tdesu_stub.c
@@ -367,9 +367,9 @@ int main()
                 close(fd);
 	    xsetenv("ICEAUTHORITY", iceauthority);
 
-	    fout = popen("iceauth >/dev/null 2>&1", "w");
+	    fout = popen(ICEAUTH_COMMAND " >/dev/null 2>&1", "w");
 	    if (!fout) {
-		perror("tdesu_stub: popen iceauth");
+		perror("tdesu_stub: popen " ICEAUTH_COMMAND);
 		exit(1);
 	    }
 	    for (i=0; host[i]; i++)
