$NetBSD$

--- qmake/generators/unix/unixmake2.cpp.orig	2020-04-10 10:04:43.000000000 +0000
+++ qmake/generators/unix/unixmake2.cpp
@@ -1386,20 +1386,6 @@ void UnixMakefileGenerator::init2()
 	    if(!project->isActiveConfig("compile_libtool"))
 		project->variables()["QMAKE_LFLAGS"] += project->variables()["QMAKE_LFLAGS_SONAME"];
 	}
-	TQString destdir = project->first("DESTDIR");
-	if ( !destdir.isEmpty() && !project->variables()["QMAKE_RPATH"].isEmpty() ) {
-	    TQString rpath_destdir = destdir;
-	    if(TQDir::isRelativePath(rpath_destdir)) {
-		TQFileInfo fi(Option::fixPathToLocalOS(rpath_destdir));
-		if(fi.convertToAbs())  //strange, shouldn't really happen
-		    rpath_destdir = Option::fixPathToTargetOS(rpath_destdir, FALSE);
-		else
-		    rpath_destdir = fi.filePath();
-	    } else {
-		rpath_destdir = Option::fixPathToTargetOS(rpath_destdir, FALSE);
-	    }
-	    project->variables()["QMAKE_LFLAGS"] += project->first("QMAKE_RPATH") + rpath_destdir;
-	}
     }
     TQStringList &quc = project->variables()["QMAKE_EXTRA_UNIX_COMPILERS"];
     for(TQStringList::Iterator it = quc.begin(); it != quc.end(); ++it) {
@@ -1428,7 +1414,7 @@ UnixMakefileGenerator::libtoolFileName()
     TQString ret = var("TARGET");
     int slsh = ret.findRev(Option::dir_sep);
     if(slsh != -1)
-	ret = ret.right(ret.length() - slsh);
+	ret = ret.right(ret.length() - slsh - 1);
     int dot = ret.find('.');
     if(dot != -1)
 	ret = ret.left(dot);
@@ -1465,13 +1451,17 @@ UnixMakefileGenerator::writeLibtoolFile(
 	t << var("TARGET");
     } else {
     	if (project->isEmpty("QMAKE_HPUX_SHLIB"))
-	    t << var("TARGET_x.y.z") << " ";
+	    t << var("TARGET_x.y.z") << " " << var("TARGET_x.y") << " ";
     	t << var("TARGET_x") << " " << var("TARGET_");
     }
     t << "'\n\n";
 
     t << "# The name of the static archive.\n"
-      << "old_library='" << lname.left(lname.length()-Option::libtool_ext.length()) << ".a'\n\n";
+      << "old_library='";
+    if(project->isActiveConfig("staticlib")) {
+	t << lname.left(lname.length()-Option::libtool_ext.length()) << ".a";
+    }
+    t << "'\n\n";
 
     t << "# Libraries that this one depends upon.\n";
     TQStringList libs;
@@ -1512,7 +1502,7 @@ UnixMakefileGenerator::pkgConfigFileName
     TQString ret = var("TARGET");
     int slsh = ret.findRev(Option::dir_sep);
     if(slsh != -1)
-	ret = ret.right(ret.length() - slsh);
+	ret = ret.right(ret.length() - slsh - 1);
     if(ret.startsWith("lib"))
 	ret = ret.mid(3);
     int dot = ret.find('.');
