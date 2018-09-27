$NetBSD: patch-Lib_distutils_command_build__ext.py,v 1.1 2018/06/17 19:21:21 adam Exp $

--- Lib/distutils/command/build_ext.py.orig	2018-04-29 22:47:33.000000000 +0000
+++ Lib/distutils/command/build_ext.py
@@ -244,6 +244,7 @@ class build_ext (Command):
             else:
                 # building python standard extensions
                 self.library_dirs.append('.')
+            self.rpath.append(sysconfig.get_config_var('LIBDIR'))
 
         # The argument parsing will result in self.define being a string, but
         # it has to be a list of 2-tuples.  All the preprocessor symbols
@@ -514,8 +515,19 @@ class build_ext (Command):
         # that go into the mix.
         if ext.extra_objects:
             objects.extend(ext.extra_objects)
+
+        # Two possible sources for extra linker arguments:
+        #   - 'extra_link_args' in Extension object
+        #   - LDFLAGS environment variable
+        # The environment variable should take precedence, and
+        # any sensible compiler will give precedence to later
+        # command line args.  Hence we combine them in order:
         extra_args = ext.extra_link_args or []
 
+        if os.environ.has_key('LDFLAGS'):
+            extra_args = list(extra_args)
+            extra_args.extend(string.split(os.environ['LDFLAGS']))
+
         # Detect target language, if not provided
         language = ext.language or self.compiler.detect_language(sources)
 
