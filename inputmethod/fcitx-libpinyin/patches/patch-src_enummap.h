$NetBSD$

* update for compatible with new libpinyin

--- src/enummap.h.orig	2013-07-15 20:34:05.000000000 +0000
+++ src/enummap.h
@@ -29,5 +29,6 @@ DoublePinyinScheme FcitxLibPinyinTransSh
 PinyinAmbiguity2 FcitxLibPinyinTransAmbiguity(FCITX_AMBIGUITY ambiguity);
 PinyinCorrection2 FcitxLibPinyinTransCorrection(FCITX_CORRECTION correction);
 int FcitxLibPinyinTransDictionary(FCITX_DICTIONARY dict);
+int FcitxLibPinyinTransZhuyinDictionary(FCITX_ZHUYIN_DICTIONARY dict);
 
 #endif
