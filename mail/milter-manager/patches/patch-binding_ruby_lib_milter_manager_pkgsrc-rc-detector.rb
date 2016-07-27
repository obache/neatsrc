$NetBSD$

* adapt to current default installation layout

--- binding/ruby/lib/milter/manager/pkgsrc-rc-detector.rb.orig	2015-06-15 05:13:40.000000000 +0000
+++ binding/ruby/lib/milter/manager/pkgsrc-rc-detector.rb
@@ -68,7 +68,7 @@ module Milter::Manager
 
     def milter_greylist_conf
       extract_parameter_from_flags(command_args, "-f") ||
-        File.join(package_prefix, "mail", "greylist.conf")
+        File.join(package_prefix, "greylist.conf")
     end
   end
 end
