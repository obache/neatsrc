$NetBSD: patch-mesonbuild_scripts_depfixer.py,v 1.1 2019/06/06 05:40:50 adam Exp $

Change to strip just relative paths in rpath for ELF.

--- mesonbuild/scripts/depfixer.py.orig	2019-05-05 19:11:16.000000000 +0000
+++ mesonbuild/scripts/depfixer.py
@@ -294,8 +294,6 @@ class Elf(DataSizes):
         self.fix_rpathtype_entry(new_rpath, DT_RUNPATH)
 
     def fix_rpathtype_entry(self, new_rpath, entrynum):
-        if isinstance(new_rpath, str):
-            new_rpath = new_rpath.encode('utf8')
         rp_off = self.get_entry_offset(entrynum)
         if rp_off is None:
             if self.verbose:
@@ -303,6 +301,14 @@ class Elf(DataSizes):
             return
         self.bf.seek(rp_off)
         old_rpath = self.read_str()
+        keep_rpath = ':'.join(filter(lambda x: x.startswith('/'), old_rpath.decode('utf-8').split(':')))
+        if keep_rpath:
+            if new_rpath:
+                new_rpath = new_rpath + ':' + keep_rpath
+            else:
+                new_rpath = keep_rpath
+        if isinstance(new_rpath, str):
+            new_rpath = new_rpath.encode('utf8')
         if len(old_rpath) < len(new_rpath):
             sys.exit("New rpath must not be longer than the old one.")
         # The linker does read-only string deduplication. If there is a
