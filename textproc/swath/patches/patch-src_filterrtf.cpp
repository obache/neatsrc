$NetBSD$

* NetBSD is missing wcpcpy(3) and wcpncpy(3).

--- src/filterrtf.cpp.orig	2013-10-30 05:24:43.000000000 +0000
+++ src/filterrtf.cpp
@@ -10,6 +10,35 @@
 #include "utils.h"
 #include "worddef.h"
 
+#ifdef __NetBSD__
+static wchar_t*
+wcpcpy (wchar_t* ws1, const wchar_t* ws2)
+{
+  while((*ws1 = *ws2) != (wchar_t)'\0')
+    {
+       ws1++;
+       ws2++;
+    }
+  return ws1;
+}
+
+static wchar_t*
+wcpncpy (wchar_t* ws1, const wchar_t* ws2, size_t n)
+{
+  while(n > 0 && (*ws1 = *ws2) != (wchar_t)'\0')
+    {
+       ws1++;
+       ws2++;
+       n--;
+    }
+  for (; n > 0; n--)
+    {
+      *ws1++ = (wchar_t)'\0';
+    }
+  return ws1 - 1;
+}
+#endif
+
 //////////////////////////////////////////////////////////////////////
 // class RTFToken
 //////////////////////////////////////////////////////////////////////
