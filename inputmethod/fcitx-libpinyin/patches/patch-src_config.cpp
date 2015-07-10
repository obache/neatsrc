$NetBSD$

* no matter libpinyin tools found or not, we can build it
* update for compatible with new libpinyin

--- src/config.cpp.orig	2013-07-15 20:34:05.000000000 +0000
+++ src/config.cpp
@@ -19,17 +19,22 @@
  ***************************************************************************/
 
 #include "eim.h"
+#include "config.h"
 
 CONFIG_BINDING_BEGIN(FcitxLibPinyinConfig)
 CONFIG_BINDING_REGISTER("Pinyin", "Incomplete", incomplete)
+#ifdef LIBPINYIN_TOOLS_FOUND
 CONFIG_BINDING_REGISTER("Pinyin", "UseTraditionalChineseData", bTraditionalDataForPinyin)
+#endif
 CONFIG_BINDING_REGISTER("Zhuyin", "Incomplete", chewingIncomplete)
 CONFIG_BINDING_REGISTER("Zhuyin", "UseTone", useTone)
 CONFIG_BINDING_REGISTER("Zhuyin", "Layout", zhuyinLayout)
 CONFIG_BINDING_REGISTER("Zhuyin", "PrevPage", hkPrevPage)
 CONFIG_BINDING_REGISTER("Zhuyin", "NextPage", hkNextPage)
 CONFIG_BINDING_REGISTER("Zhuyin", "CandidateModifiers", candidateModifiers)
+#ifdef LIBPINYIN_TOOLS_FOUND
 CONFIG_BINDING_REGISTER("Zhuyin", "UseSimplifiedChineseData", bSimplifiedDataForZhuyin)
+#endif
 CONFIG_BINDING_REGISTER("Shuangpin", "Scheme", spScheme)
 CONFIG_BINDING_REGISTER("Correction", "VU", cr[FCITX_CR_V_U])
 CONFIG_BINDING_REGISTER("Correction", "GNNG", cr[FCITX_CR_GN_NG])
@@ -56,7 +61,19 @@ CONFIG_BINDING_REGISTER("Dictionary", "G
 CONFIG_BINDING_REGISTER("Dictionary", "History", dict[FCITX_DICT_HISTORY])
 CONFIG_BINDING_REGISTER("Dictionary", "Life", dict[FCITX_DICT_LIFE])
 CONFIG_BINDING_REGISTER("Dictionary", "Nature", dict[FCITX_DICT_NATURE])
-CONFIG_BINDING_REGISTER("Dictionary", "Scitech", dict[FCITX_DICT_SCITECH])
+CONFIG_BINDING_REGISTER("Dictionary", "People", dict[FCITX_DICT_PEOPLE])
+CONFIG_BINDING_REGISTER("Dictionary", "Scitech", dict[FCITX_DICT_SCIENCE])
 CONFIG_BINDING_REGISTER("Dictionary", "Society", dict[FCITX_DICT_SOCIETY])
 CONFIG_BINDING_REGISTER("Dictionary", "Sport", dict[FCITX_DICT_SPORT])
+CONFIG_BINDING_REGISTER("Dictionary", "Technology", dict[FCITX_DICT_TECHNOLOGY])
+CONFIG_BINDING_REGISTER("Dictionary Zhuyin", "Art", dict[FCITX_ZHUYIN_DICT_ART])
+CONFIG_BINDING_REGISTER("Dictionary Zhuyin", "Culture", dict[FCITX_ZHUYIN_DICT_CULTURE])
+CONFIG_BINDING_REGISTER("Dictionary Zhuyin", "Economy", dict[FCITX_ZHUYIN_DICT_ECONOMY])
+CONFIG_BINDING_REGISTER("Dictionary Zhuyin", "Geology", dict[FCITX_ZHUYIN_DICT_GEOLOGY])
+CONFIG_BINDING_REGISTER("Dictionary Zhuyin", "History", dict[FCITX_ZHUYIN_DICT_HISTORY])
+CONFIG_BINDING_REGISTER("Dictionary Zhuyin", "Life", dict[FCITX_ZHUYIN_DICT_LIFE])
+CONFIG_BINDING_REGISTER("Dictionary Zhuyin", "Nature", dict[FCITX_ZHUYIN_DICT_NATURE])
+CONFIG_BINDING_REGISTER("Dictionary Zhuyin", "Scitech", dict[FCITX_ZHUYIN_DICT_SCITECH])
+CONFIG_BINDING_REGISTER("Dictionary Zhuyin", "Society", dict[FCITX_ZHUYIN_DICT_SOCIETY])
+CONFIG_BINDING_REGISTER("Dictionary Zhuyin", "Sport", dict[FCITX_ZHUYIN_DICT_SPORT])
 CONFIG_BINDING_END()
