$NetBSD$

* NetBSD is missing wcpcpy(3) and wcpncpy(3).

--- src/filterrtf.cpp.orig	2018-08-14 05:33:16.000000000 +0000
+++ src/filterrtf.cpp
@@ -10,6 +10,36 @@
 #include "utils.h"
 #include "worddef.h"
 
+#ifdef __NetBSD__
+static wchar_t*
+wcpcpy (wchar_t* ws1, const wchar_t* ws2)
+{
+  while((*ws1 = *ws2) != L'\0')
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
+  wchar_t* p;
+
+  while(n > 0 && (*ws1 = *ws2) != L'\0')
+    {
+       ws1++;
+       ws2++;
+       n--;
+    }
+  p = ws1;
+  for (; n > 0; n--)
+    *(++ws1) = L'\0';
+  return p;
+}
+#endif
+
 //////////////////////////////////////////////////////////////////////
 // class RTFToken
 //////////////////////////////////////////////////////////////////////
