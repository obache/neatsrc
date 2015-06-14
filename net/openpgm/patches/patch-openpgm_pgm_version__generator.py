$NetBSD$

* Fixes for python3

--- openpgm/pgm/version_generator.py.orig	2012-12-04 02:57:22.000000000 +0000
+++ openpgm/pgm/version_generator.py
@@ -10,3 +10,3 @@ build_rev = filter (str.isdigit, "$Revis
 
-print """
+print ("""
 /* vim:ts=8:sts=8:sw=4:noai:noexpandtab
@@ -52,3 +52,3 @@ const char* pgm_build_revision = "%s";
 /* eof */
-"""%(build_date, build_time, platform.system(), platform.machine(), build_rev)
+"""%(build_date, build_time, platform.system(), platform.machine(), build_rev))
 
