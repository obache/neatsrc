$NetBSD$

--- perl/TrapReceiver/Makefile.PL.orig	2014-12-08 20:23:22.000000000 +0000
+++ perl/TrapReceiver/Makefile.PL
@@ -107,6 +107,9 @@ sub InitMakeParams {
     else {
 	$opts = NetSNMPGetOpts();
 	$Params{'LDDLFLAGS'} = "$Config{lddlflags} " . `$opts->{'nsconfig'} --ldflags`;
+	chomp($Params{'LDDLFLAGS'});
+	$Params{'LDDLFLAGS'} .= " " . $Config{'ccdlflags'};
+	chomp($Params{'LDDLFLAGS'});
 	$Params{'LIBS'} = '-lnetsnmptrapd ' . `$opts->{'nsconfig'} --base-agent-libs`;
 	chomp($Params{'LIBS'});
 	if (!$ENV{'NETSNMP_CCFLAGS'}) {
