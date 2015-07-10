$NetBSD$

* no matter libpinyin tools found or not, we can build it
* update for compatible with new libpinyin

--- cmake/FindLibpinyin.cmake.orig	2013-07-15 20:34:05.000000000 +0000
+++ cmake/FindLibpinyin.cmake
@@ -16,7 +16,7 @@ if(LIBPINYIN_INCLUDE_DIR AND LIBPINYIN_L
 endif(LIBPINYIN_INCLUDE_DIR AND LIBPINYIN_LIBRARIES)
 
 find_package(PkgConfig REQUIRED)
-pkg_check_modules(PC_LIBPINYIN "libpinyin>=0.9.91")
+pkg_check_modules(PC_LIBPINYIN "libpinyin>=1.1.91")
 _pkgconfig_invoke("libpinyin" PC_LIBPINYIN LIBPINYININCLUDEDIR "" "--variable=libpinyinincludedir")
 _pkgconfig_invoke("libpinyin" LIBPINYIN PKGDATADIR "" "--variable=pkgdatadir")
 _pkgconfig_invoke("libpinyin" LIBPINYIN EXECPREFIX "" "--variable=exec_prefix")
@@ -38,9 +38,6 @@ find_package_handle_standard_args(Libpin
                                   LIBPINYIN_LIBRARIES
                                   LIBPINYIN_INCLUDE_DIR
                                   LIBPINYIN_PKGDATADIR
-                                  LIBPINYIN_GEN_BINARY_FILES
-                                  LIBPINYIN_GEN_UNIGRAM
-                                  LIBPINYIN_IMPORT_INTERPOLATION
                                   PC_LIBPINYIN_FOUND
                                   )
 
