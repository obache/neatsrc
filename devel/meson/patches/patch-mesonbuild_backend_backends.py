$NetBSD$

* inject install dir for dependency shlib to rpath

--- mesonbuild/backend/backends.py.orig	2019-07-09 16:34:42.000000000 +0000
+++ mesonbuild/backend/backends.py
@@ -404,6 +404,18 @@ class Backend:
                 return True
         return False
 
+    def rpaths_for_internal_shared_libraries(self, target, exclude_system=True):
+        paths = []
+
+        for la in target.get_all_link_deps():
+                if not isinstance(la, build.SharedLibrary):
+                    continue
+                libdirs = la.get_install_dir(self.environment)[0]
+                if exclude_system:
+                    libdirs = filter(lambda x: not self._libdir_is_system(x, target.compilers, self.environment), libdirs)
+                paths.extend(map(lambda x: os.path.join(self.environment.get_prefix(), x), libdirs))
+        return paths
+
     def rpaths_for_bundled_shared_libraries(self, target, exclude_system=True):
         paths = []
         for dep in target.external_deps:
@@ -436,6 +448,7 @@ class Backend:
         else:
             result = OrderedSet()
             result.add('meson-out')
+        result.update(self.rpaths_for_internal_shared_libraries(target))
         result.update(self.rpaths_for_bundled_shared_libraries(target))
         return tuple(result)
 
