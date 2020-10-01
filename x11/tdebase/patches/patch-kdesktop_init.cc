$NetBSD$

--- kdesktop/init.cc.orig	2015-09-23 03:07:44.000000000 +0000
+++ kdesktop/init.cc
@@ -105,6 +105,9 @@ static void copyDirectoryFile(const TQSt
     cmd += " ";
     cmd += TDEProcess::quote(dir+"/.directory");
     system( TQFile::encodeName(cmd) );
+    cmd = "chmod u+w ";
+    cmd += TDEProcess::quote(dir+"/.directory");
+    system( TQFile::encodeName(cmd) );
   }
 }
 
