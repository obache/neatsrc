$NetBSD$

* for pytho3

--- wrapper/ibus/setup/main.py.orig	2016-05-08 13:57:00.000000000 +0000
+++ wrapper/ibus/setup/main.py
@@ -37,7 +37,12 @@
 import sys
 import os
 from os import path
-import gtk
+try:
+    import gtk
+except Importerror:
+    from gi import require_version as gi_require_version
+    gi_require_version('Gtk', '3.0')
+    from gi.repository import Gtk as gtk
 import ibus
 import gettext
 import locale
