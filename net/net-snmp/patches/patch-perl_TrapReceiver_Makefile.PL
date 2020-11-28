$NetBSD: patch-perl_TrapReceiver_Makefile.PL,v 1.1 2016/06/06 14:11:35 he Exp $

* prevent to link perl module with libperl

--- perl/TrapReceiver/Makefile.PL.orig	2018-07-16 14:33:40.000000000 +0000
+++ perl/TrapReceiver/Makefile.PL
@@ -108,7 +108,7 @@ sub TrapReceiverInitMakeParams {
     else {
 	$opts = NetSNMPGetOpts();
 	$Params{'LDDLFLAGS'} = "$Config{lddlflags} " . `$opts->{'nsconfig'} --ldflags`;
-	$Params{'LIBS'} = '-lnetsnmptrapd ' . `$opts->{'nsconfig'} --base-agent-libs`;
+	$Params{'LIBS'} = '-Wl,--no-copy-dt-needed-entries -lnetsnmptrapd ' . `$opts->{'nsconfig'} --base-agent-libs`;
 	chomp($Params{'LIBS'});
 	if (!$ENV{'NETSNMP_CCFLAGS'}) {
 	    $Params{'CCFLAGS'} = `$opts->{'nsconfig'} --cflags`;
