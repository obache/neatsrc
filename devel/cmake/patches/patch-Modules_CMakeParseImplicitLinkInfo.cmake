$NetBSD$

* hide pkgsrc buildlink directory 

--- Modules/CMakeParseImplicitLinkInfo.cmake.orig	2018-09-07 10:49:08.000000000 +0000
+++ Modules/CMakeParseImplicitLinkInfo.cmake
@@ -163,6 +163,9 @@ function(CMAKE_PARSE_IMPLICIT_LINK_INFO 
     foreach(d IN LISTS implicit_${t}_tmp)
       get_filename_component(dir "${d}" ABSOLUTE)
       string(FIND "${dir}" "${CMAKE_FILES_DIRECTORY}/" pos)
+      if (pos LESS 0 AND DEFINED PKGSRC_BUILDLINK_BASEDIR)
+        string(FIND "${dir}" "${PKGSRC_BUILDLINK_BASEDIR}/" pos)
+      endif()
       if(NOT pos LESS 0)
         set(msg ", skipping non-system directory")
       else()
