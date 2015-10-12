$NetBSD$

* sys/time.h is required for struct timespec before wsconsio.h on NetBSD

--- src/ws.h.orig	2015-08-29 08:48:29.000000000 +0000
+++ src/ws.h
@@ -14,6 +14,7 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
+#include <sys/time.h>
 #include <dev/wscons/wsconsio.h>
 
 /* #undef DEBUG */
