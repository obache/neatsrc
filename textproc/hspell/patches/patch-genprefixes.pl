$NetBSD$

* perl>=5.26 removed "." from @INC

--- genprefixes.pl.orig	2003-08-31 22:13:46.000000000 +0000
+++ genprefixes.pl
@@ -1,6 +1,6 @@
 #!/usr/bin/perl -w
 
-require "PrefixBits.pl";
+require "./PrefixBits.pl";
 
 sub find_prefixes {
 	my $INQUISITIVE_HE=shift;
