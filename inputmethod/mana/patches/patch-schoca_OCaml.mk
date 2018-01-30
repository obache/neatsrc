$NetBSD$

* fix typos
* require old unsafe-string mode

--- schoca/OCaml.mk.orig	2006-04-24 15:24:44.000000000 +0000
+++ schoca/OCaml.mk
@@ -20,8 +20,8 @@
 
 OCAMLFIND=ocamlfind
 DEBUGFLAG=-g
-BCFLAGS=$(INCLUDES) $(DEBUGFLAG) 
-NCFLAGS=$(INCLUDES)
+BCFLAGS=$(INCLUDES) $(DEBUGFLAG) -unsafe-string
+NCFLAGS=$(INCLUDES) -unsafe-string
 AUTOMLI=automli
 
 CC=ocamlc
@@ -140,7 +140,7 @@ LIB_INSTALL=META $(LIBRARY).cma $(LIBRAR
 DESTDIRFLAG=$(if $(DESTDIR),-destdir $(DESTDIR))
 
 install-lib: $(LIB_INSTALL)
-	ocamlfind remove $(DESTDURFLAG) $(LIBRARY)
+	ocamlfind remove $(DESTDIRFLAG) $(LIBRARY)
 	ocamlfind install $(DESTDIRFLAG) $(LIBRARY) $(LIB_INSTALL)
 
 else
@@ -163,7 +163,7 @@ PREDICATES=
 SYNTAX=-syntax camlp4o
 OCAMLCFLAGS=$(INCLUDES) $(EXPANDEDPACKAGES) $(CFLAGS) $(BCFLAGS) $(PREDICATES) \
 	$(SYNTAX)
-OCAMLOPTFLAGS=$(INCLUDES) $(EXPANDEDPACKAGES) $(CFLAGS)  $(NCFALGS) $(PREDICATES) \
+OCAMLOPTFLAGS=$(INCLUDES) $(EXPANDEDPACKAGES) $(CFLAGS)  $(NCFLAGS) $(PREDICATES) \
 	$(SYNTAX) $(OPTFLAGS)
 
 
