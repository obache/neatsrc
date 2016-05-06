$NetBSD: patch-Modules_ManageTranslation.cmake,v 1.4 2014/12/13 06:33:15 obache Exp $

* PKGLOCALEDIR support

--- Modules/ManageTranslation.cmake.orig	2016-02-25 14:53:41.000000000 +0000
+++ Modules/ManageTranslation.cmake
@@ -368,7 +368,7 @@ FUNCTION(MANAGE_POT_FILE_INTERNAL showWa
     SOURCE_ARCHIVE_CONTENTS_ADD("${potFile}" ${srcs} ${depends})
     SET(cleanList "${potFile}")
 
-    SET(_moInstallRoot "${DATA_DIR}/locale")
+    SET(_moInstallRoot "${LOCALE_DIR}")
     ## Not only POT, but also PO and MO as well
     FOREACH(_l ${MANAGE_TRANSLATION_LOCALES})
 	## PO file
