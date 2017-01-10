$NetBSD$

* fix a typo

--- schoca/OCaml.mk.orig	2006-04-24 15:24:44.000000000 +0000
+++ schoca/OCaml.mk
@@ -140,7 +140,7 @@ LIB_INSTALL=META $(LIBRARY).cma $(LIBRAR
 DESTDIRFLAG=$(if $(DESTDIR),-destdir $(DESTDIR))
 
 install-lib: $(LIB_INSTALL)
-	ocamlfind remove $(DESTDURFLAG) $(LIBRARY)
+	ocamlfind remove $(DESTDIRFLAG) $(LIBRARY)
 	ocamlfind install $(DESTDIRFLAG) $(LIBRARY) $(LIB_INSTALL)
 
 else
