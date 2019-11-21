$NetBSD$

* exactly declare as int

--- programs/dsdm/proxy.c.orig	2019-10-12 21:43:45.000000000 +0000
+++ programs/dsdm/proxy.c
@@ -185,7 +185,7 @@ extern Atom ATOM_WM_STATE;
 
 unsigned char *GetInterestProperty();
 
-static ForwardConversion();
+static int ForwardConversion();
 
 static drop_info_t drop_table[DROP_TABLE_MAX];
 Atom ATOM_SUN_DND_TRIGGER;
@@ -1133,7 +1133,7 @@ CopyTargets(Display *dpy, Atom prop, Win
     
 /* Forward the SelectionNotify to the receiver.
    Returns True if we get ATOM_SUN_DND_DONE or ATOM_SUN_SELECTION_END */
-static
+static int
 ForwardConversion(XSelectionEvent *event, drop_info_t *drop_info)
 {
     int ol_done = False;
