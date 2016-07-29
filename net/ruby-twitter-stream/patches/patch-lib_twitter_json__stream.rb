$NetBSD$

* EventMachine::BufferedTokenizer API changes

--- lib/twitter/json_stream.rb.orig	2016-07-29 07:11:02.000000000 +0000
+++ lib/twitter/json_stream.rb
@@ -6,8 +6,6 @@ require 'http/parser'
 
 module Twitter
   class JSONStream < EventMachine::Connection
-    MAX_LINE_LENGTH = 1024*1024
-
     # network failure reconnections
     NF_RECONNECT_START = 0.25
     NF_RECONNECT_ADD   = 0.25
@@ -116,7 +114,7 @@ module Twitter
     end
 
     def unbind
-      if @state == :stream && !@buffer.empty?
+      if @state == :stream
         parse_stream_line(@buffer.flush)
       end
       schedule_reconnect if @options[:auto_reconnect] && !@gracefully_closed
@@ -203,7 +201,7 @@ module Twitter
       @code    = 0
       @headers = {}
       @state   = :init
-      @buffer  = BufferedTokenizer.new("\r", MAX_LINE_LENGTH)
+      @buffer  = BufferedTokenizer.new("\r")
       @stream  = ''
 
       @parser  = Http::Parser.new
