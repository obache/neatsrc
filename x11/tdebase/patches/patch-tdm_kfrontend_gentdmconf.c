$NetBSD$

--- tdm/kfrontend/gentdmconf.c.orig	2015-09-23 03:07:45.000000000 +0000
+++ tdm/kfrontend/gentdmconf.c
@@ -666,7 +666,7 @@ static const char def_session1[] =
 "    xsess_tmp=";
 static const char def_session2[] =
 "\n"
-"    $SHELL -c \"if (-f /etc/csh.login) source /etc/csh.login; if (-f ~/.login) source ~/.login; /bin/sh -c export -p >! $xsess_tmp\"\n"
+"    $SHELL -c \"if (-f /etc/csh.login) source /etc/csh.login; if (-f ~/.login) source ~/.login; /bin/sh -c 'export -p' >! $xsess_tmp\"\n"
 "    . $xsess_tmp\n"
 "    rm -f $xsess_tmp\n"
 "    ;;\n"
