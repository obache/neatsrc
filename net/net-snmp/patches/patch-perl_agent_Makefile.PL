$NetBSD: patch-perl_agent_Makefile.PL,v 1.2 2016/06/06 14:11:35 he Exp $

* prevent to link perl module with libperl

--- perl/agent/Makefile.PL.orig	2018-07-16 14:33:40.000000000 +0000
+++ perl/agent/Makefile.PL
@@ -80,7 +80,7 @@ sub AgentInitMakeParams {
     else {
 	$opts = NetSNMPGetOpts();
 	$Params{'LDDLFLAGS'} = "$Config{lddlflags} " . `$opts->{'nsconfig'} --ldflags`;
-	$Params{'LIBS'}   = `$opts->{'nsconfig'} --base-agent-libs`;
+	$Params{'LIBS'}   = "-Wl,--no-copy-dt-needed-entries " . `$opts->{'nsconfig'} --base-agent-libs`;
 	chomp($Params{'LIBS'});
 	$Params{'CCFLAGS'} = `$opts->{'nsconfig'} --cflags`;
 	chomp($Params{'CCFLAGS'});
