$NetBSD$

* append install dir for dependency shlibs to install_rpath

--- mesonbuild/backend/backends.py.orig	2020-09-10 16:39:18.000000000 +0000
+++ mesonbuild/backend/backends.py
@@ -487,6 +487,18 @@ class Backend:
                         raise MesonException('Invalid arg for --just-symbols, {} is a directory.'.format(dir))
         return dirs
 
+    def rpaths_for_internal_shared_libraries(self, target, exclude_system=True):
+        paths = []
+
+        for la in target.get_all_link_deps():
+            if not isinstance(la, build.SharedLibrary):
+                continue
+            libdirs = la.get_install_dir(self.environment)[0]
+            if exclude_system:
+                libdirs = filter(lambda x: not self._libdir_is_system(x, target.compilers, self.environment), libdirs)
+            paths.extend(map(lambda x: os.path.join(self.environment.get_prefix(), x), libdirs))
+        return paths
+
     def rpaths_for_bundled_shared_libraries(self, target, exclude_system=True):
         paths = []
         for dep in target.external_deps:
@@ -524,6 +536,11 @@ class Backend:
             result.add('meson-out')
         result.update(self.rpaths_for_bundled_shared_libraries(target))
         target.rpath_dirs_to_remove.update([d.encode('utf8') for d in result])
+        install_rpath = OrderedSet()
+        if target.install_rpath:
+            install_rpath.update(target.install_rpath.split(':'))
+        install_rpath.update(self.rpaths_for_internal_shared_libraries(target))
+        target.install_rpath = ':'.join(install_rpath)
         return tuple(result)
 
     @staticmethod
