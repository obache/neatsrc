$NetBSD$

--- src/kernel/qfont_x11.cpp.orig	2020-04-10 10:04:43.000000000 +0000
+++ src/kernel/qfont_x11.cpp
@@ -75,7 +75,7 @@ Q_EXPORT bool tqt_has_xft = FALSE;
 TQt::HANDLE qt_xft_handle(const TQFont &font)
 {
     TQFontEngine *engine = font.d->engineForScript( TQFontPrivate::defaultScript );
-    if (!engine->type() == TQFontEngine::Xft)
+    if (engine->type() != TQFontEngine::Xft)
         return 0;
     return (long)static_cast<TQFontEngineXft *>(engine)->font();
 }
