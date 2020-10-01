$NetBSD$

--- kded/khostname.cpp.orig	2020-04-10 23:08:30.000000000 +0000
+++ kded/khostname.cpp
@@ -16,6 +16,8 @@
  *  Boston, MA 02110-1301, USA.
  **/
 
+#include <config.h>
+
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
@@ -236,7 +238,7 @@ void KHostName::changeDcop()
       ::symlink(fname.data(), compatLink.data()); // Compatibility link
 
       // Update .ICEauthority
-      TQString cmd = "iceauth list "+TDEProcess::quote("netid="+oldNetId);
+      TQString cmd = ICEAUTH_COMMAND " list "+TDEProcess::quote("netid="+oldNetId);
       FILE *iceFile = popen(TQFile::encodeName(cmd), "r");
       if (!iceFile)
       {
@@ -271,7 +273,7 @@ void KHostName::changeDcop()
          if (netId != oldNetId)
             continue;
 
-         cmd = "iceauth add ";
+         cmd = ICEAUTH_COMMAND " add ";
          cmd += TDEProcess::quote(protName);
          cmd += " '' ";
          cmd += TDEProcess::quote(newNetId);
@@ -288,7 +290,7 @@ void KHostName::changeDcop()
    char* xauthlocalhostname = getenv("XAUTHLOCALHOSTNAME");
    if (!xauthlocalhostname || !oldNetId.contains(xauthlocalhostname))
    {
-      TQString cmd = "iceauth remove "+TDEProcess::quote("netid="+oldNetId);
+      TQString cmd = ICEAUTH_COMMAND " remove "+TDEProcess::quote("netid="+oldNetId);
       system(TQFile::encodeName(cmd));
       unlink(origFName.data());
       origFName = DCOPClient::dcopServerFileOld(oldName); // Compatibility link
