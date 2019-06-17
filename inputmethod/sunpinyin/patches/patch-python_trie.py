$NetBSD$

* python2to3

--- python/trie.py.orig	2019-06-17 04:59:39.959710784 +0000
+++ python/trie.py
@@ -161,7 +161,7 @@ class DATrie (object):
                 if progress_cb:
                     progress_cb ()
 
-        for i in xrange (self.chr_encoder (max(trie.root.trans))+1):
+        for i in range (self.chr_encoder (max(trie.root.trans))+1):
             if self.check[i] == -1:
                 self.check[i] = 0
 
@@ -272,7 +272,7 @@ def test ():
         v, l = match_longest (datrie, s+'b')
         assert (len(s) == l and valid_syllables[s] == v)
 
-    print 'test executed successfully'
+    print ('test executed successfully')
 
 if __name__ == "__main__":
     test ()
