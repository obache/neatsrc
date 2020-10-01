$NetBSD$

--- dcop/dcopclient.cpp.orig	2020-04-10 23:08:30.000000000 +0000
+++ dcop/dcopclient.cpp
@@ -41,6 +41,7 @@ CONNECTION WITH THE SOFTWARE OR THE USE 
 #include <sys/stat.h>
 #include <sys/file.h>
 #include <sys/socket.h>
+#include <sys/un.h>
 #include <fcntl.h>
 #include <unistd.h>
 
@@ -219,6 +220,11 @@ TQCString DCOPClient::iceauthPath()
 	ret = SearchPathA(NULL,"iceauth.exe",NULL,sizeof(szPath)/sizeof(szPath[0]),szPath,&pszFilePart);
 	if(ret != 0)
 		return TQCString(szPath);
+#elif defined ICEAUTH_PATH
+    if (access(ICEAUTH_PATH, X_OK) == 0)
+    {
+	return TQCString(ICEAUTH_PATH);
+    }
 #else
     TQCString path = ::getenv("PATH");
     if (path.isEmpty())
@@ -713,10 +719,12 @@ bool DCOPClient::isSuspended() const
     return !d->notifier->isEnabled();
 }
 
-#ifdef SO_PEERCRED
+#if defined(SO_PEERCRED) || defined(LOCAL_PEEREID)
+#define USE_PEER_IS_US
 // Check whether the remote end is owned by the same user.
 static bool peerIsUs(int sockfd)
 {
+#ifdef SO_PEERCRED
 #if defined(__OpenBSD__)
     struct sockpeercred cred;
 #else
@@ -726,6 +734,13 @@ static bool peerIsUs(int sockfd)
     if (getsockopt(sockfd, SOL_SOCKET, SO_PEERCRED, &cred, &siz) != 0)
         return false;
     return (cred.uid == getuid());
+#elif defined LOCAL_PEEREID
+    struct unpcbid cred;
+    socklen_t siz = sizeof(cred);
+    if (getsockopt(sockfd, 0, LOCAL_PEEREID, &cred, &siz) != 0 || siz != sizeof(cred))
+        return false;
+    return (cred.unp_euid == geteuid());
+#endif
 }
 #else
 // Check whether the socket is owned by the same user.
@@ -871,7 +886,7 @@ bool DCOPClient::attachInternal( bool re
         return false;
     }
 
-#ifdef SO_PEERCRED
+#ifdef USE_PEER_IS_US
     d->foreign_server = !peerIsUs(socket());
 #else
     d->foreign_server = !isServerSocketOwnedByUser(d->serverAddr);
