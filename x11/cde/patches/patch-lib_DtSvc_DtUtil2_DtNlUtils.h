$NetBSD$

* fix ctype(3) usage

--- lib/DtSvc/DtUtil2/DtNlUtils.h.orig	2019-10-12 21:43:45.000000000 +0000
+++ lib/DtSvc/DtUtil2/DtNlUtils.h
@@ -43,6 +43,7 @@
 #include <langinfo.h>
 #endif
 
+#include <ctype.h>
 #include <X11/Intrinsic.h>
 
 
@@ -95,8 +96,8 @@ extern int _Dt_isdigit(char *s);
 #define DtCharCount(s1)      (Dt_charCount(s1))
 #define DtNextChar(s)	     (is_multibyte?_Dt_NextChar(s):((s)+1))
 #define DtPrevChar(st,s)     (is_multibyte?_Dt_PrevChar(st,s):((s)-1))
-#define DtIsspace(s)	     (is_multibyte?_Dt_isspace(s):isspace(*(s)))
-#define DtIsdigit(s)	     (is_multibyte?_Dt_isdigit(s):isdigit(*(s)))
+#define DtIsspace(s)	     (is_multibyte?_Dt_isspace(s):isspace((unsigned char)*(s)))
+#define DtIsdigit(s)	     (is_multibyte?_Dt_isdigit(s):isdigit((unsigned char)*(s)))
 
 #else	/* NLS16 */
 
@@ -111,8 +112,8 @@ extern int _Dt_isdigit(char *s);
 #define DtCharCount(s1)      (strlen(s1))
 #define DtNextChar(s)	     ((s)+1)
 #define DtPrevChar(st,s)     ((s)-1)
-#define DtIsspace(s)	     (isspace(*s))
-#define DtIsdigit(s)	     (isdigit(*s))
+#define DtIsspace(s)	     (isspace((unsigned char)*s))
+#define DtIsdigit(s)	     (isdigit((unsigned char)*s))
 #endif /* NLS16 */
 
 extern char * _DtGetNthChar( 
