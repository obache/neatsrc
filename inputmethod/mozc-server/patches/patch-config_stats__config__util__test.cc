$NetBSD: patch-config_stats__config__util__test.cc,v 1.1 2013/04/29 09:52:17 ryoon Exp $

--- config/stats_config_util_test.cc.orig	2016-01-10 19:41:41.000000000 +0000
+++ config/stats_config_util_test.cc
@@ -696,11 +696,11 @@ TEST(StatsConfigUtilTestAndroid, Default
 }
 #endif  // OS_ANDROID
 
-#if defined(OS_LINUX) || defined(OS_NACL)
+#if defined(OS_LINUX) || defined(OS_NACL) || defined(OS_NETBSD)
 TEST(StatsConfigUtilTestLinux, DefaultValueTest) {
   EXPECT_FALSE(StatsConfigUtil::IsEnabled());
 }
-#endif  // OS_LINUX || OS_NACL
+#endif  // OS_LINUX || OS_NACL || OS_NETBSD
 
 #else  // !GOOGLE_JAPANESE_INPUT_BUILD
 TEST(StatsConfigUtilTestNonOfficialBuild, DefaultValueTest) {
