$NetBSD$

--- config.h.cmake.orig	2020-04-10 23:08:30.000000000 +0000
+++ config.h.cmake
@@ -1,8 +1,14 @@
 /* config.h.in.  Generated from configure.in by autoheader.  */
 
+/* Define where ispell libdir is */
+#cmakedefine ISPELL_LIBDIR "@ISPELL_LIBDIR@"
+
 /* Define where aspell data dir is */
 #define ASPELL_DATADIR "@ASPELL_DATADIR@"
 
+/* Define default spell checker */
+#define DEFAULT_SPELL_CHECKER KS_CLIENT_@DEFAULT_SPELL_CHECKER@
+
 /* Avahi API 0.6 */
 #cmakedefine HAVE_DNSSD 1
 #cmakedefine AVAHI_API_0_6 1
@@ -15,9 +21,6 @@
 /* Define to 1 if using `alloca.c'. */
 #undef C_ALLOCA
 
-/* Define where your dcop binary is */
-#cmakedefine DCOP_PATH "@DCOP_PATH@"
-
 /* Use su or sudo */
 #define DEFAULT_SUPER_USER_COMMAND "@DEFAULT_SUPER_USER_COMMAND@"
 
@@ -66,8 +69,11 @@
 /* Define if you have strvercmp prototype */
 #cmakedefine HAVE_STRVERCMP_PROTO 1
 
-/* Define to 1 if execinfo.h exists and defines backtrace (GLIBC >= 2.1) */
+/* Define to 1 you have backtrace information library */
 #cmakedefine HAVE_BACKTRACE 1
+#ifdef HAVE_BACKTRACE
+#define BACKTRACE_H <@Backtrace_HEADER@>
+#endif
 
 /* Define to 1 if gcc (or may be some over compiller) provides abi::__cxa_demangle() */
 #cmakedefine HAVE_ABI_CXA_DEMANGLE 1
@@ -156,7 +162,7 @@
 #cmakedefine HAVE_CUPS_1_6 1
 
 /* Define to 1 if you have the declaration of `getservbyname_r', and to 0 if you don't. */
-#undef HAVE_DECL_GETSERVBYNAME_R
+#cmakedefine01 HAVE_DECL_GETSERVBYNAME_R
 
 /* Define to 1 if you have the <dirent.h> header file, and it defines `DIR'. */
 #cmakedefine HAVE_DIRENT_H 1
@@ -921,6 +927,14 @@
 /* Defined if your system has XRandR support */
 #cmakedefine XRANDR_SUPPORT 1
 
+/* Defines the executable of iceauth */
+#cmakedefine ICEAUTH_PATH "@ICEAUTH_PATH@"
+#ifdef ICEAUTH_PATH
+#define ICEAUTH_COMMAND ICEAUTH_PATH
+#else
+#define ICEAUTH_COMMAND "iceauth"
+#endif
+
 /*
  * jpeg.h needs HAVE_BOOLEAN, when the system uses boolean in system
  * headers and I'm too lazy to write a configure test as long as only
@@ -1143,11 +1157,7 @@ __END_DECLS
 
 
 
-/*
- * On HP-UX, the declaration of vsnprintf() is needed every time !
- */
-
-#if !defined(HAVE_VSNPRINTF) || defined(hpux)
+#if !defined(HAVE_VSNPRINTF_PROTO)
 #if __STDC__
 #include <stdarg.h>
 #include <stdlib.h>
@@ -1158,10 +1168,10 @@ __END_DECLS
 extern "C"
 #endif
 int vsnprintf(char *str, size_t n, char const *fmt, va_list ap);
+int snprintf(char *str, size_t n, char const *fmt, ...);
 #ifdef __cplusplus
 extern "C"
 #endif
-int snprintf(char *str, size_t n, char const *fmt, ...);
 #endif
 
 
