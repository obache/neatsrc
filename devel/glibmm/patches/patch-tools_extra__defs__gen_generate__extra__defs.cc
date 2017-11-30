$NetBSD$

* gcc < 4.9 missing the prototype

--- tools/extra_defs_gen/generate_extra_defs.cc.orig	2017-09-12 15:02:29.000000000 +0000
+++ tools/extra_defs_gen/generate_extra_defs.cc
@@ -87,7 +87,11 @@ get_property_with_node_name(
       // Replace newlines with \n.
       // A string default value can contain newline characters.
       // gmmproc removes all newlines when it reads .defs files.
+#if defined(__GNUC__) && (__GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ < 9))
+      defString = std::regex_replace(std::string(defCString), std::regex("\n"), std::string("\\n"));
+#else
       defString = std::regex_replace(defCString, std::regex("\n"), "\\n");
+#endif
     }
     else
       defString = ""; // A NULL string pointer becomes an empty string.
