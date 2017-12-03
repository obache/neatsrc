$NetBSD$

* fix for LLVM>=5.0 (taken from upstream)

--- src/gallium/auxiliary/gallivm/lp_bld_misc.cpp.orig	2016-05-09 12:51:42.000000000 +0000
+++ src/gallium/auxiliary/gallivm/lp_bld_misc.cpp
@@ -343,14 +343,20 @@ class DelegatingJITMemoryManager : publi
       virtual void registerEHFrames(uint8_t *Addr, uint64_t LoadAddr, size_t Size) {
          mgr()->registerEHFrames(Addr, LoadAddr, Size);
       }
-      virtual void deregisterEHFrames(uint8_t *Addr, uint64_t LoadAddr, size_t Size) {
-         mgr()->deregisterEHFrames(Addr, LoadAddr, Size);
-      }
 #else
       virtual void registerEHFrames(llvm::StringRef SectionData) {
          mgr()->registerEHFrames(SectionData);
       }
 #endif
+#if HAVE_LLVM >= 0x0500
+      virtual void deregisterEHFrames() {
+         mgr()->deregisterEHFrames();
+      }
+#elif HAVE_LLVM >= 0x0304
+      virtual void deregisterEHFrames(uint8_t *Addr, uint64_t LoadAddr, size_t Size) {
+         mgr()->deregisterEHFrames(Addr, LoadAddr, Size);
+      }
+#endif
       virtual void *getPointerToNamedFunction(const std::string &Name,
                                               bool AbortOnFailure=true) {
          return mgr()->getPointerToNamedFunction(Name, AbortOnFailure);
