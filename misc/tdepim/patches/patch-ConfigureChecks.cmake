$NetBSD$

* fix missing gnokii.h check
* set xxx_INCLUDE_DIRS (semicolon separated) to proper variable

--- ConfigureChecks.cmake.orig	2021-04-10 10:45:46.000000000 +0000
+++ ConfigureChecks.cmake
@@ -59,6 +59,10 @@ if( WITH_GNOKII AND (BUILD_KADDRESSBOOK 
   pkg_search_module( GNOKII gnokii )
   if( NOT GNOKII_FOUND )
     tde_message_fatal( "gnokii are requested, but was not found on your system" )
+  else( )
+    tde_save_and_set( CMAKE_REQUIRED_INCLUDES "${GNOKII_INCLUDE_DIRS}" )
+    check_include_file( "gnokii.h" HAVE_GNOKII_H )
+    tde_restore( CMAKE_REQUIRED_INCLUDES )
   endif( )
 endif( )
 
@@ -144,10 +148,12 @@ if( BUILD_LIBTDENETWORK OR BUILD_CERTMAN
 
   # check for various GPGME features
   tde_save( CMAKE_CXX_FLAGS )
+  tde_save( CMAKE_REQUIRED_INCLUDES )
   tde_save( CMAKE_REQUIRED_LIBRARIES )
   string( REGEX REPLACE "-include tqt.h" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" )
   # See FIXME above regarding -D_FILE_OFFSET_BITS=64
-  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GPGME_INCLUDE_DIRS} -D_FILE_OFFSET_BITS=64")
+  set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_FILE_OFFSET_BITS=64")
+  set( CMAKE_REQUIRED_INCLUDES "${GPGME_INCLUDE_DIRS}")
   set( CMAKE_REQUIRED_LIBRARIES "${GPGME_LIBRARIES}")
 
   # check for GPGME_KEYLIST_MODE_VALIDATE
@@ -206,6 +212,7 @@ if( BUILD_LIBTDENETWORK OR BUILD_CERTMAN
 
   # done checking for GPGME features
   tde_restore( CMAKE_CXX_FLAGS )
+  tde_restore( CMAKE_REQUIRED_INCLUDES )
   tde_restore( CMAKE_REQUIRED_LIBRARIES )
 
 endif( )
@@ -237,6 +244,25 @@ if( BUILD_KARM AND WITH_XSCREENSAVER )
   endif( )
 endif( )
 
+if( BUILD_TDERESOURCES AND WITH_GROUPWISE )
+  check_symbol_exists( strrchr "string.h" HAVE_STRRCHR )
+  check_symbol_exists( strtod "stdlib.h" HAVE_STRTOD )
+  check_symbol_exists( sscanf "stdio.h" HAVE_SSCANF )
+  check_symbol_exists( strtol "stdlib.h" HAVE_STRTOL )
+  check_symbol_exists( strtoul "stdlib.h" HAVE_STRTOUL )
+  check_symbol_exists( strtoll "stdlib.h" HAVE_STRTOLL )
+  check_symbol_exists( strtoull "stdlib.h" HAVE_STRTOULL )
+  check_symbol_exists( gettimeofday "sys/time.h" HAVE_GETTIMEOFDAY )
+  check_include_file( "sys/timeb.h" HAVE_SYS_TIMEB_H )
+  check_symbol_exists( ftime "sys/timeb.h" HAVE_FTIME )
+  check_symbol_exists( rand_r "stdlib.h" HAVE_RAND_R )
+  check_symbol_exists( gmtime_r "time.h" HAVE_GMTIME_R )
+  check_symbol_exists( localtime_r "time.h" HAVE_LOCALTIME_R )
+  check_symbol_exists( timegm "time.h" HAVE_TIMEGM )
+  check_symbol_exists( wctomb "stdlib.h" HAVE_WCTOMB )
+  check_symbol_exists( mbtowc "stdlib.h" HAVE_MBTOWC )
+  check_symbol_exists( isnan "math.h" HAVE_ISNAN )
+endif ( )
 
 # required stuff
 find_package( TQt )
