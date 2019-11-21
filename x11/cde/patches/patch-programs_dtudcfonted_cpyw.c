$NetBSD$

* fix prototype mismatch

--- programs/dtudcfonted/cpyw.c.orig	2019-10-12 21:43:45.000000000 +0000
+++ programs/dtudcfonted/cpyw.c
@@ -344,7 +344,7 @@ static void
 delScProc( int value )
 {
     int		i;
-    extern int RelToAbsSq();
+    extern int RelToAbsSq( int from, int cnt);
 
     dn.sq_top = RelToAbsSq( dn.sq_start, value - dn.sq_start);
     for ( i=0 ; i < dn.disp_num ; i++ ) {
