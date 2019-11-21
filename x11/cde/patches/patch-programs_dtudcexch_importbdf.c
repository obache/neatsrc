$NetBSD$

* exactly declare as `int'

--- programs/dtudcexch/importbdf.c.orig	2019-10-12 21:43:45.000000000 +0000
+++ programs/dtudcexch/importbdf.c
@@ -63,13 +63,13 @@
         } \
 }
 
-static impFileConvInit();
-static impGetGpfInf();
-static impReadBdfHeaderAndPut();
-static impMergePtn();
-static impModifyPtn();
-static impInsertPtn();
-static impWriteSnf();
+static int impFileConvInit();
+static int impGetGpfInf();
+static int impReadBdfHeaderAndPut();
+static int impMergePtn();
+static int impModifyPtn();
+static int impInsertPtn();
+static int impWriteSnf();
 static int impWritePtnToBdf();
 static int impPutDefaultChars();
 static int impReadBdfToMemory();
@@ -356,7 +356,7 @@ int	*bdf_codelist
 * sub functions
 */
 
-static
+static int
 impFileConvInit(
 struct btophead	*r_udc,
 struct btophead	*r_gpf,
@@ -470,7 +470,7 @@ struct ptobhead	*w_gpf
 
 
 
-static
+static int
 impGetGpfInf(
 struct btophead *r_gpf,
 struct ptobhead *w_gpf,
@@ -499,7 +499,7 @@ int		bdf_codenum
 
 
 
-static
+static int
 impReadBdfHeaderAndPut(
 struct btophead *r_gpf,
 struct ptobhead *w_gpf,
@@ -550,7 +550,7 @@ char	*buf
 }
 
 
-static
+static int
 impMergePtn(
 struct	btophead *r_udc,
 struct	btophead *r_gpf,
@@ -611,7 +611,7 @@ int	*bdf_codelist
 	return	0;
 }
 
-static
+static int
 impModifyPtn(struct btophead *r_udc, struct btophead *r_gpf, char *buf, int ix)
 {
 	int 	mwidth, msize, rtn;
@@ -636,7 +636,7 @@ impModifyPtn(struct btophead *r_udc, str
 	return	0;
 }
 
-static
+static int
 impInsertPtn(
 struct btophead *r_udc,
 struct btophead *r_gpf,
@@ -681,7 +681,7 @@ int 	ix
 	return(0);
 }
 
-static
+static int
 impWriteSnf(struct btophead *r_gpf, struct ptobhead *w_gpf)
 {
 	w_gpf->zoomf = 0;
