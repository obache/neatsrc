$NetBSD$

--- Lib/distutils/command/build_ext.py.orig	2020-12-21 16:25:24.000000000 +0000
+++ Lib/distutils/command/build_ext.py
@@ -235,6 +235,7 @@ class build_ext(Command):
             if not sysconfig.python_build:
                 # building third party extensions
                 self.library_dirs.append(sysconfig.get_config_var('LIBDIR'))
+                self.rpath.append(sysconfig.get_config_var('LIBDIR'))
             else:
                 # building python standard extensions
                 self.library_dirs.append('.')
