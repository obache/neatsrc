$NetBSD$

* Honor pkg-config result

--- cmake/modules/FindICU.cmake.orig	2018-08-14 19:49:51.000000000 +0000
+++ cmake/modules/FindICU.cmake
@@ -28,7 +28,11 @@ if(DEFINED ICU_BASE)
   file(TO_NATIVE_PATH "${ICU_BASE}" icu_root)
 else()
   find_package(PkgConfig QUIET)
-  pkg_check_modules(PC_LibICU QUIET icu-i18n)
+  pkg_check_modules(PC_LibICU QUIET icu-uc)
+  if(PC_LibICU_FOUND)
+    set(ICU_INCLUDE_DIR "${PC_LibICU_INCLUDEDIR}")
+    set(ICU_LIBRARY "${PC_LibICU_LDFLAGS}")
+  endif()
 endif()
 
 # Look for the header file.
@@ -90,6 +94,10 @@ if(ICU_INCLUDE_DIR AND ICU_LIBRARY)
   set(ICU_VERSION "${ICU_MAJOR_VERSION}.${ICU_MINOR_VERSION}")
 
   # Look for the ICU internationalization libraries
+  pkg_check_modules(PC_LibICU_I18N QUIET icu-i18n)
+  if(PC_LibICU_I18N_FOUND)
+    set(ICU_I18N_LIBRARY "${PC_LibICU_I18N_LDFLAGS}")
+  endif()
   find_library(
     ICU_I18N_LIBRARY
     NAMES icuin icui18n cygicuin cygicuin32
