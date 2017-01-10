$NetBSD$

* Split Haiku off BeOS

--- cpan/ExtUtils-MakeMaker/lib/ExtUtils/MM.pm.orig	2015-05-16 12:23:24.000000000 +0000
+++ cpan/ExtUtils-MakeMaker/lib/ExtUtils/MM.pm
@@ -59,7 +59,7 @@ if( $^O eq 'MSWin32' ) {
 $Is{UWIN}   = $^O =~ /^uwin(-nt)?$/;
 $Is{Cygwin} = $^O eq 'cygwin';
 $Is{NW5}    = $Config{osname} eq 'NetWare';  # intentional
-$Is{BeOS}   = ($^O =~ /beos/i or $^O eq 'haiku');
+$Is{BeOS}   = $^O =~ /beos/i;
 $Is{DOS}    = $^O eq 'dos';
 if( $Is{NW5} ) {
     $^O = 'NetWare';
