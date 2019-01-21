$NetBSD: patch-numpy_distutils_fcompiler_g95.py,v 1.3 2015/04/17 00:41:38 wen Exp $

Band aid to make sure that pic_flags is actually used.

--- numpy/distutils/fcompiler/g95.py.orig	2018-08-19 02:17:10.000000000 +0000
+++ numpy/distutils/fcompiler/g95.py
@@ -1,6 +1,7 @@
 # http://g95.sourceforge.net/
 from __future__ import division, absolute_import, print_function
 
+import sys
 from numpy.distutils.fcompiler import FCompiler
 
 compilers = ['G95FCompiler']
@@ -19,9 +20,9 @@ class G95FCompiler(FCompiler):
 
     executables = {
         'version_cmd'  : ["<F90>", "--version"],
-        'compiler_f77' : ["g95", "-ffixed-form"],
-        'compiler_fix' : ["g95", "-ffixed-form"],
-        'compiler_f90' : ["g95"],
+        'compiler_f77' : ["g95", "-ffixed-form", "-fpic"],
+        'compiler_fix' : ["g95", "-ffixed-form", "-fpic"],
+        'compiler_f90' : ["g95", "-fpic"],
         'linker_so'    : ["<F90>", "-shared"],
         'archiver'     : ["ar", "-cr"],
         'ranlib'       : ["ranlib"]
@@ -37,6 +38,10 @@ class G95FCompiler(FCompiler):
     def get_flags_debug(self):
         return ['-g']
 
+    def runtime_library_dir_option(self, dir):
+        sep = ',' if sys.platform == 'darwin' else '='
+        return '-Wl,-rpath%s%s' % (sep, dir)
+
 if __name__ == '__main__':
     from distutils import log
     from numpy.distutils import customized_fcompiler
