$NetBSD$

--- programs/dtcm/libDtCmP/props.c.orig	2015-05-09 23:09:11.000000000 +0000
+++ programs/dtcm/libDtCmP/props.c
@@ -343,11 +343,11 @@ init_props()
 
     dflt = def_props[CP_DATEORDERING];
     str = catgets(libdtcm_catd, 1, 1, dflt);
-    def_props[CP_DATEORDERING] = strdup(str);
+    def_props[CP_DATEORDERING] = cm_strdup(str);
 
     dflt = def_props[CP_DEFAULTDISP];
     str = catgets(libdtcm_catd, 1, 2, dflt);
-    def_props[CP_DEFAULTDISP] = strdup(str);
+    def_props[CP_DEFAULTDISP] = cm_strdup(str);
 }
 
 extern boolean_t
