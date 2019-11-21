$NetBSD$

* <unistd.h> for unlink(2), pipe(2), read(2), write(2)

--- programs/dtpdmd/dtpdmdP.h.orig	2019-10-12 21:43:45.000000000 +0000
+++ programs/dtpdmd/dtpdmdP.h
@@ -41,6 +41,7 @@
 #include <setjmp.h>
 #include <sys/wait.h>
 #include <sys/stat.h>
+#include <unistd.h>
 #include "X11/Xlibint.h"
 #include "X11/Intrinsic.h"
 #include "X11/Xatom.h"
