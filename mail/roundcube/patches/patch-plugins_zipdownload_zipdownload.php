$NetBSD$

* Use RFC-6266 way

--- plugins/zipdownload/zipdownload.php.orig	2019-08-27 17:15:56.000000000 +0000
+++ plugins/zipdownload/zipdownload.php
@@ -334,10 +334,7 @@ class zipdownload extends rcube_plugin
 
         $rcmail->output->nocacheing_headers();
 
-        if ($browser->ie)
-            $filename = rawurlencode($filename);
-        else
-            $filename = addcslashes($filename, '"');
+        $filename = rawurlencode($filename);
 
         // send download headers
         header("Content-Type: application/octet-stream");
@@ -347,7 +344,7 @@ class zipdownload extends rcube_plugin
 
         // don't kill the connection if download takes more than 30 sec.
         @set_time_limit(0);
-        header("Content-Disposition: attachment; filename=\"". $filename ."\"");
+        header("Content-Disposition: attachment; filename*=UTF-8''". $filename);
         header("Content-length: " . filesize($tmpfname));
         readfile($tmpfname);
     }
