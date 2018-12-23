$NetBSD$

* use C comment style instead of C++

--- uim/uim-x-util.c.orig	2017-08-14 00:07:27.000000000 +0000
+++ uim/uim-x-util.c
@@ -45,7 +45,7 @@ uim_x_keysym2ukey(KeySym xkeysym)
 	ukey = (int)(xkeysym);
     else if (xkeysym >= XK_F1 && xkeysym <= XK_F35)
 	ukey = (int)(xkeysym - XK_F1 + UKey_F1);
-    // GTK+ and Qt don't support dead_stroke yet
+    /* GTK+ and Qt don't support dead_stroke yet */
     else if (xkeysym >= XK_dead_grave && xkeysym <= XK_dead_horn)
 	ukey = (int)(xkeysym - XK_dead_grave + UKey_Dead_Grave);
     else if (xkeysym >= XK_Kanji && xkeysym <= XK_Eisu_toggle)
