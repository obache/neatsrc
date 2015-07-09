$NetBSD$

* kill Linux-izm

--- googlepinyin.py.orig	2012-03-20 23:36:23.000000000 +0000
+++ googlepinyin.py
@@ -11,7 +11,7 @@ import os
 import sys
 import glob
 
-libc = ctypes.CDLL("libc.so.6")
+libc = ctypes.CDLL(ctypes.util.find_library('c'))
 ime_pinyin = ctypes.CDLL(ctypes.util.find_library('googlepinyin'), use_errno=True)
 
 _a = lambda path: os.path.exists(path) and path or ""
