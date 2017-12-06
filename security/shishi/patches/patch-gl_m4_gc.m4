$NetBSD$

* update for gcrypt>=1.6

--- gl/m4/gc.m4.orig	2013-04-02 22:48:10.000000000 +0000
+++ gl/m4/gc.m4
@@ -1,5 +1,5 @@
-# gc.m4 serial 9
-dnl Copyright (C) 2005-2013 Free Software Foundation, Inc.
+# gc.m4 serial 10
+dnl Copyright (C) 2005-2015 Free Software Foundation, Inc.
 dnl This file is free software; the Free Software Foundation
 dnl gives unlimited permission to copy and/or distribute it,
 dnl with or without modifications, as long as this notice is preserved.
@@ -10,14 +10,16 @@ AC_DEFUN([gl_GC],
     AS_HELP_STRING([--with-libgcrypt], [use libgcrypt for low-level crypto]),
     libgcrypt=$withval, libgcrypt=no)
   if test "$libgcrypt" != no; then
-    AC_LIB_HAVE_LINKFLAGS([gcrypt], [gpg-error], [
-#include <gcrypt.h>
-/* GCRY_MODULE_ID_USER was added in 1.4.4 and gc-libgcrypt.c
-   will fail on startup if we don't have 1.4.4 or later, so
-   test for it early. */
-#if !defined GCRY_MODULE_ID_USER
-error too old libgcrypt
-#endif
-])
+    # gc-libgcrypt.c will fail on startup if we don't have
+    # 1.4.4 or later, so test for it early. */
+    gl_good_gcrypt=no
+    m4_ifdef([AM_PATH_LIBGCRYPT],
+      [AM_PATH_LIBGCRYPT([1.4.4], [gl_good_gcrypt=yes],
+        [AC_MSG_ERROR([libgcrypt is too old])])])
+    if test "x$gl_good_gcrypt" != xno; then
+      AC_LIB_HAVE_LINKFLAGS([gcrypt], [gpg-error], [#include <gcrypt.h>])
+    else
+      AC_MSG_ERROR([libgcrypt not found])
+    fi
   fi
 ])
