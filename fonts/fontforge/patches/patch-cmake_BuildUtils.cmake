$NetBSD$

* fix to expand the variable

--- cmake/BuildUtils.cmake.orig	2020-03-03 09:24:02.000000000 +0000
+++ cmake/BuildUtils.cmake
@@ -102,7 +102,7 @@ endfunction()
 function(set_default_rpath)
   list(FIND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES "${CMAKE_INSTALL_PREFIX}/lib" _is_system_dir)
   if(_is_system_dir LESS 0)
-    list(APPEND CMAKE_INSTALL_RPATH "\${CMAKE_INSTALL_PREFIX}/lib")
+    list(APPEND CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
   endif()
   if(APPLE)
     list(APPEND CMAKE_INSTALL_RPATH "@loader_path/../lib")
