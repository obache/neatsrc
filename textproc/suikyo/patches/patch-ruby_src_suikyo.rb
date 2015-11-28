$NetBSD$

* ruby-2.0 M17N support

--- ruby/src/suikyo.rb.orig	2005-03-29 02:07:09.000000000 +0000
+++ ruby/src/suikyo.rb
@@ -1 +1,2 @@
+# coding: euc-jp
 # suikyo.rb: Romaji-Hiragana conversion library for Ruby
@@ -11,5 +12,2 @@
 
-$KCODE = 'e'
-require 'jcode'
-require 'kconv'
 require 'suikyo/suikyo-config'
@@ -219,3 +217,3 @@ class SuikyoTable
     comment_flag = false
-    open(filepath, "r").readlines.each{|line|
+    open(filepath, "r:EUC-JP").readlines.each{|line|
       line.chomp!
