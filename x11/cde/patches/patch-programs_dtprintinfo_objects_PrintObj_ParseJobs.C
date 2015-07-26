$NetBSD$

--- programs/dtprintinfo/objects/PrintObj/ParseJobs.C.orig	2015-05-09 23:09:11.000000000 +0000
+++ programs/dtprintinfo/objects/PrintObj/ParseJobs.C
@@ -870,7 +870,7 @@ void LocalPrintJobs(char *printer, char 
 #if defined(__osf__)
    sprintf(buf, "LANG=C lpstat -o%s", printer);
 #endif
-#if defined(linux) || defined(__OpenBSD__)
+#if defined(linux) || defined(__OpenBSD__) || defined(__NetBSD__)
    snprintf(buf, 1000, "LANG=C lpq -P%s", printer);
 #elif defined(__FreeBSD__)
    snprintf(buf, 1000, "LANG=C /usr/local/bin/lpq -P%s", printer);
