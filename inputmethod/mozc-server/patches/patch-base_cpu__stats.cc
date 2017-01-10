$NetBSD: patch-base_cpu__stats.cc,v 1.2 2016/05/16 11:51:49 ryoon Exp $

--- base/cpu_stats.cc.orig	2016-01-10 19:41:41.000000000 +0000
+++ base/cpu_stats.cc
@@ -123,7 +123,7 @@ float CPUStats::GetSystemCPULoad() {
 
 #endif  // OS_MACOSX
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL) || defined(OS_NETBSD)
   // NOT IMPLEMENTED
   // TODO(taku): implement Linux version
   // can take the info from /proc/stats
@@ -178,7 +178,7 @@ float CPUStats::GetCurrentProcessCPULoad
       TimeValueTToInt64(task_times_info.system_time);
 #endif  // OS_MACOSX
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL) || defined(OS_NETBSD)
   // not implemented
   const uint64 total_times = 0;
   const uint64 cpu_times = 0;
@@ -210,7 +210,7 @@ size_t CPUStats::GetNumberOfProcessors()
   return static_cast<size_t>(basic_info.avail_cpus);
 #endif  // OS_MACOSX
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_NACL) || defined(OS_NETBSD)
   // Not implemented
   return 1;
 #endif  // OS_LINUX
