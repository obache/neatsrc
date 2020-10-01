$NetBSD$

--- qmake/project.cpp.orig	2020-04-10 10:04:43.000000000 +0000
+++ qmake/project.cpp
@@ -724,7 +724,7 @@ TQMakeProject::isActiveConfig(const TQSt
 	static char *buffer = NULL;
 	if(!buffer)
 	    buffer = (char *)malloc(1024);
-	int l = readlink(Option::mkfile::qmakespec, buffer, 1024);
+	int l = readlink(Option::mkfile::qmakespec, buffer, 1023);
 	if(l != -1) {
 	    buffer[l] = '\0';
 	    TQString r = buffer;
