$NetBSD$

* Fix "Unescaped left brace in regex is deprecated" for perl-5.24

--- filter/hnf.pl.orig	2008-05-09 07:32:14.000000000 +0000
+++ filter/hnf.pl
@@ -244,7 +244,7 @@ sub get_uri ($$) {
         $uri = '?%year%month%hiday#%year%month%day0'; # for hns-1.x
       }
       $uri =~ s/%%/\34/g;
-      $uri =~ s/%{?([a-z]+)}?/$param{$1}/g;
+      $uri =~ s/%\{?([a-z]+)}?/$param{$1}/g;
       $uri =~ s/\34/%/g;
       $uri = $hnf::diary_uri . $uri;
       $uri =~ s/%7E/~/i;
