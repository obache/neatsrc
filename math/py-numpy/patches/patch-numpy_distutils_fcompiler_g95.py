$NetBSD: patch-numpy_distutils_fcompiler_g95.py,v 1.3 2015/04/17 00:41:38 wen Exp $

Band aid to make sure that pic_flags is actually used.

--- numpy/distutils/fcompiler/g95.py.orig	2020-09-03 04:22:06.000000000 +0000
+++ numpy/distutils/fcompiler/g95.py
@@ -1,4 +1,5 @@
 # http://g95.sourceforge.net/
+import sys
 from numpy.distutils.fcompiler import FCompiler
 
 compilers = ['G95FCompiler']
@@ -17,9 +18,9 @@ class G95FCompiler(FCompiler):
 
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
@@ -35,6 +36,10 @@ class G95FCompiler(FCompiler):
     def get_flags_debug(self):
         return ['-g']
 
+    def runtime_library_dir_option(self, dir):
+        sep = ',' if sys.platform == 'darwin' else '='
+        return '-Wl,-rpath%s%s' % (sep, dir)
+
 if __name__ == '__main__':
     from distutils import log
     from numpy.distutils import customized_fcompiler
