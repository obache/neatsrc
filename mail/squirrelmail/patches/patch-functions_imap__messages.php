$NetBSD$

* fail back to UTF-8 with "NO" response (maybe bad charset)

--- functions/imap_messages.php.orig	2015-01-03 03:56:32.000000000 +0000
+++ functions/imap_messages.php
@@ -198,7 +198,11 @@ function sqimap_get_sort_order($imap_str
     }
     if (!empty($sort_on[$sort])) {
         $query = "SORT ($sort_on[$sort]) ".strtoupper($default_charset).' ALL';
-        $sort_test = sqimap_run_command_list ($imap_stream, $query, true, $response, $message, $uid_support);
+        $sort_test = sqimap_run_command_list ($imap_stream, $query, false, $response, $message, $uid_support);
+    	if (preg_match("/NO/", $response)) {
+        	$query = "SORT ($sort_on[$sort]) UTF-8 ALL";
+        	$sort_test = sqimap_run_command_list ($imap_stream, $query, false, $response, $message, $uid_support);
+	}
     }
     if (isset($sort_test[0])) {
       for ($i=0,$iCnt=count($sort_test);$i<$iCnt;++$i) {
