--- base/port.h.orig	2015-06-07 16:16:23.000000000 +0900
+++ base/port.h
@@ -130,6 +130,10 @@
 #define AS_STRING(x)   AS_STRING_INTERNAL(x)
 #define AS_STRING_INTERNAL(x)   #x
 
+// gcc>=46 has nullptr, otherwise use __null instead.
+#if defined(__GNUC__) && __GNUC__ * 1000 + __GNUC__MINOR__ < 4006
+#define nullptr __null
+#endif
 
 // TODO(yukawa): Simplify following includes
 #include "base/flags.h"
