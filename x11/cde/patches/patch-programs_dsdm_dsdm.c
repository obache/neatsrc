$NetBSD$

* <unistd.h> for fork(2)
* missing prototype

--- programs/dsdm/dsdm.c.orig	2019-10-12 21:43:45.000000000 +0000
+++ programs/dsdm/dsdm.c
@@ -69,6 +69,7 @@
 #else	/* SVR4 */
 #include <strings.h>
 #endif	/* SVR4 */
+#include <unistd.h>
 
 #define XFreeDefn	char *
 
@@ -98,6 +99,8 @@
 #ifdef PROXY
 extern Window GetAtomWindow();
 extern Atom ATOM_MOTIF_RECEIVER_INFO;
+extern void ProxyInit(Display *dpy, Window dsdm_win);
+extern void ProxyMain(Display *dpy, XEvent *event);
 Window proxy_win;
 #endif
 
