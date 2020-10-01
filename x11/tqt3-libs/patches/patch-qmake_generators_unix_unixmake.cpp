$NetBSD$

--- qmake/generators/unix/unixmake.cpp.orig	2020-04-10 10:04:43.000000000 +0000
+++ qmake/generators/unix/unixmake.cpp
@@ -343,7 +343,7 @@ UnixMakefileGenerator::init()
 		if(libtoolify[i].startsWith("QMAKE_LINK") || libtoolify[i] == "QMAKE_AR_CMD") {
 		    libtool_flags += " --mode=link";
 		    if(project->isActiveConfig("staticlib")) {
-			libtool_flags += " -static";
+			comp_flags += " -static";
 		    } else {
 			if(!project->isEmpty("QMAKE_LIB_FLAG")) {
 			    int maj = project->first("VER_MAJ").toInt();
@@ -352,18 +352,16 @@ UnixMakefileGenerator::init()
 			    comp_flags += " -version-info " + TQString::number(10*maj + min) +
 					  ":" + TQString::number(pat) + ":0";
 			    if(libtoolify[i] != "QMAKE_AR_CMD") {
-				TQString rpath = Option::output_dir;
-				if(!project->isEmpty("DESTDIR")) {
-				    rpath = project->first("DESTDIR");
-				    if(TQDir::isRelativePath(rpath))
-					rpath.prepend(Option::output_dir + Option::dir_sep);
+				TQString rpath = project->first("target.path");
+				if(rpath.right(1) != Option::dir_sep) {
+				    rpath += Option::dir_sep;
 				}
 				comp_flags += " -rpath " + Option::fixPathToTargetOS(rpath, FALSE);
 			    }
 			}
 		    }
 		    if(project->isActiveConfig("plugin"))
-			libtool_flags += " -module";
+			comp_flags += " -module";
 		} else {
 		    libtool_flags += " --mode=compile";
 		}
@@ -763,7 +761,7 @@ UnixMakefileGenerator::defaultInstall(co
 	    TQString src_lt = var("QMAKE_ORIG_TARGET");
 	    int slsh = src_lt.findRev(Option::dir_sep);
 	    if(slsh != -1)
-		src_lt = src_lt.right(src_lt.length() - slsh);
+		src_lt = src_lt.right(src_lt.length() - slsh - 1);
 	    int dot = src_lt.find('.');
 	    if(dot != -1)
 		src_lt = src_lt.left(dot);
@@ -786,7 +784,7 @@ UnixMakefileGenerator::defaultInstall(co
 	    TQString src_pc = var("QMAKE_ORIG_TARGET");
 	    int slsh = src_pc.findRev(Option::dir_sep);
 	    if(slsh != -1)
-		src_pc = src_pc.right(src_pc.length() - slsh);
+		src_pc = src_pc.right(src_pc.length() - slsh - 1);
 	    int dot = src_pc.find('.');
 	    if(dot != -1)
 		src_pc = src_pc.left(dot);
