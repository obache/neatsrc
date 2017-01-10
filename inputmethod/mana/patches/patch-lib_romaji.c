$NetBSD$

* for str*

--- lib/romaji.c.orig	2005-08-07 18:05:59.000000000 +0000
+++ lib/romaji.c
@@ -32,6 +32,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include "romaji.h"
 
 /* カタカナ → ローマ字変換表 */
