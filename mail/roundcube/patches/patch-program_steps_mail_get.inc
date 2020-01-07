$NetBSD$

* Use RFC 6266 way

--- program/steps/mail/get.inc.orig	2019-08-27 17:15:56.000000000 +0000
+++ program/steps/mail/get.inc
@@ -269,15 +269,15 @@ if (empty($_GET['_thumb']) && $attachmen
     // don't kill the connection if download takes some more time
     @set_time_limit(3600);
 
-    $filename    = $browser->ie ? rawurlencode($filename) : addcslashes($filename, '"');
     $disposition = !empty($_GET['_download']) ? 'attachment' : 'inline';
 
     // add filename extension if missing
     if (!pathinfo($filename, PATHINFO_EXTENSION) && ($extensions = rcube_mime::get_mime_extensions($mimetype))) {
         $filename .= '.' . $extensions[0];
     }
+    $filename    = rawurlencode($filename);
 
-    header("Content-Disposition: $disposition; filename=\"$filename\"");
+    header("Content-Disposition: $disposition; filename*=UTF-8''$filename");
 
     // handle tiff to jpeg conversion
     if (!empty($convert2jpeg)) {
