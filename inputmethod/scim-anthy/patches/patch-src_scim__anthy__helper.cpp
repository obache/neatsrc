$NetBSD$

* add gtk3+ support
* resolve deprecated conversion from string constant to "char*"

--- src/scim_anthy_helper.cpp.orig	2008-04-24 03:49:53.000000000 +0000
+++ src/scim_anthy_helper.cpp
@@ -175,9 +175,9 @@ slot_imengine_event (const HelperAgent *
         if (!reader.get_data (id) || !reader.get_data (time_msec))
             break;
         TimeoutContext *ctx = new TimeoutContext (ic, uuid, id);
-        guint timeout_id = gtk_timeout_add_full (time_msec,
+        guint timeout_id = g_timeout_add_full (G_PRIORITY_DEFAULT,
+												 time_msec,
                                                  timeout_func,
-                                                 NULL,
                                                  (gpointer) ctx,
                                                  timeout_ctx_destroy_func);
         timeout_ids[ic][id] = timeout_id;
@@ -191,7 +191,7 @@ slot_imengine_event (const HelperAgent *
             timeout_ids[ic].find (id) != timeout_ids[ic].end ())
         {
             guint tid = timeout_ids[ic][id];
-            gtk_timeout_remove (tid);
+            g_source_remove (tid);
         }
         break;
     }
@@ -234,8 +234,8 @@ run (const String &display, const Config
     char **argv = new char * [4];
     int    argc = 3;
 
-    argv [0] = "anthy-imengine-helper";
-    argv [1] = "--display";
+    argv [0] = const_cast<char*> ("anthy-imengine-helper");
+    argv [1] = const_cast<char*> ("--display");
     argv [2] = const_cast<char *> (display.c_str ());
     argv [3] = 0;
  
