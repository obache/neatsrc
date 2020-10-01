$NetBSD$

--- qmake/generators/makefile.cpp.orig	2020-04-10 10:04:43.000000000 +0000
+++ qmake/generators/makefile.cpp
@@ -1183,7 +1183,7 @@ MakefileGenerator::init()
 	Option::fixPathToTargetOS(imgfile);
 	if(!project->isEmpty("UI_DIR") || !project->isEmpty("UI_SOURCES_DIR")) {
 	    if(imgfile.find(Option::dir_sep) != -1)
-		imgfile = imgfile.right(imgfile.findRev(Option::dir_sep) + 1);
+		imgfile = imgfile.mid(imgfile.findRev(Option::dir_sep) + 1);
 	    imgfile.prepend( (project->isEmpty("UI_DIR") ? project->first("UI_SOURCES_DIR") :
 			    project->first("UI_DIR")) );
 	    v["QMAKE_IMAGE_COLLECTION"] = TQStringList(imgfile);
@@ -1433,7 +1433,7 @@ MakefileGenerator::write()
 	TQString prl = var("TARGET");
 	int slsh = prl.findRev(Option::dir_sep);
 	if(slsh != -1)
-	    prl = prl.right(prl.length() - slsh);
+	    prl = prl.right(prl.length() - slsh - 1);
 	int dot = prl.find('.');
 	if(dot != -1)
 	    prl = prl.left(dot);
