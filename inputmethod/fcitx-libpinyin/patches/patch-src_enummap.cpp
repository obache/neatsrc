$NetBSD$

* update for compatible with new libpinyin

--- src/enummap.cpp.orig	2013-07-15 20:34:05.000000000 +0000
+++ src/enummap.cpp
@@ -120,7 +120,9 @@ static const int dictMap[] =
     10,
     11,
     12,
-    13
+    13,
+    14,
+    15,
 };
 
 int FcitxLibPinyinTransDictionary(FCITX_DICTIONARY dict)
@@ -130,3 +132,25 @@ int FcitxLibPinyinTransDictionary(FCITX_
     assert(sz == sz2);
     return dictMap[dict];
 }
+
+static const int dictMapZhuyin[] =
+{
+    4,
+    5,
+    6,
+    7,
+    8,
+    9,
+    10,
+    11,
+    12,
+    13
+};
+
+int FcitxLibPinyinTransZhuyinDictionary(FCITX_ZHUYIN_DICTIONARY dict)
+{
+    int sz = sizeof(dictMapZhuyin) / sizeof(dictMapZhuyin[0]);
+    int sz2 = FCITX_ZHUYIN_DICT_LAST + 1;
+    assert(sz == sz2);
+    return dictMapZhuyin[dict];
+}
