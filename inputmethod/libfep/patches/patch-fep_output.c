$NetBSD$

* fix to build with NetBSD curses
  * _putchar is used as macro in curses.h
  * tputs() variable argment is NCurses extension

--- fep/output.c.orig	2012-03-29 01:17:21.000000000 +0000
+++ fep/output.c
@@ -46,7 +46,7 @@
 static int tty_out;
 
 static int
-_putchar (int c)
+_fep_putchar (int c)
 {
   char _c = c;
   write (tty_out, &_c, 1);
@@ -57,7 +57,7 @@ void
 _fep_putp (Fep *fep, const char *str)
 {
   tty_out = fep->tty_out;
-  tputs (str, 1, _putchar);
+  tputs (str, 1, _fep_putchar);
 }
 
 void
@@ -86,7 +86,7 @@ _fep_output_set_attributes (Fep *fep, co
 void
 _fep_output_change_scroll_region (Fep *fep, int start, int end)
 {
-  const char *csr = tparm (change_scroll_region, start, end);
+  const char *csr = tparm (change_scroll_region, start, end, 0, 0, 0, 0, 0, 0, 0);
   _fep_putp (fep, csr);
   fep->cursor.row = fep->cursor.col = 0;
 }
@@ -244,7 +244,7 @@ _fep_output_goto_status_text (Fep *fep, 
 void
 _fep_output_cursor_address (Fep *fep, int row, int col)
 {
-  char *str = tparm (cursor_address, row, col);
+  char *str = tparm (cursor_address, row, col, 0, 0, 0, 0, 0, 0, 0);
   _fep_putp (fep, str);
   fep->cursor.row = row;
   fep->cursor.col = col;
@@ -468,7 +468,7 @@ _fep_output_init_screen (Fep *fep)
 
   _fep_output_change_scroll_region (fep, 0, fep->winsize.ws_row - 1);
 
-  str = tparm (clear_screen, 2);
+  str = tparm (clear_screen, 2, 0, 0, 0, 0, 0, 0, 0, 0);
   _fep_putp (fep, str);
 
   _fep_putp (fep, cursor_invisible);
@@ -480,11 +480,11 @@ _fep_output_init_screen (Fep *fep)
     {
       FepPoint cursor0, cursor1;
 
-      str = tparm (cursor_address, 1, 1);
+      str = tparm (cursor_address, 1, 1, 0, 0, 0, 0, 0, 0, 0);
       _fep_putp (fep, str);
       _fep_output_dsr_cpr (fep, &cursor0);
 
-      str = tparm (cursor_address, cursor0.row, cursor0.col);
+      str = tparm (cursor_address, cursor0.row, cursor0.col, 0, 0, 0, 0, 0, 0, 0);
       _fep_putp (fep, str);
       _fep_output_dsr_cpr (fep, &cursor1);
 
@@ -494,7 +494,7 @@ _fep_output_init_screen (Fep *fep)
       fep->cursor.row -= fep->cursor_diff.row;
       fep->cursor.col -= fep->cursor_diff.col;
 
-      str = tparm (cursor_address, fep->cursor.row, fep->cursor.col);
+      str = tparm (cursor_address, fep->cursor.row, fep->cursor.col, 0, 0, 0, 0, 0, 0, 0);
       _fep_putp (fep, str);
     }
   _fep_putp (fep, cursor_normal);
