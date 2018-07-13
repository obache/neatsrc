$NetBSD$

* Fix ICAL_CHECK_VERSION macro

--- src/libical/ical_file.cmake.orig	2018-02-27 15:34:25.000000000 +0000
+++ src/libical/ical_file.cmake
@@ -37,7 +37,7 @@ file(APPEND ${ICAL_FILE_H_FILE} "extern 
 file(APPEND ${ICAL_FILE_H_FILE} "#endif\n")
 
 foreach(_current_FILE ${COMBINEDHEADERSICAL})
-  file(STRINGS ${_current_FILE} _lines)
+  file(STRINGS ${_current_FILE} _lines NEWLINE_CONSUME)
   foreach(_currentLINE ${_lines})
     string(REGEX REPLACE "#include \"ical.*\\.h\"" "" _currentLINE "${_currentLINE}")
     string(REGEX REPLACE "#include \"config.*\\.h\"" "" _currentLINE "${_currentLINE}")
