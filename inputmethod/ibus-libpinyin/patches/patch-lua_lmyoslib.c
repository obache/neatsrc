$NetBSD: patch-lua_lmyoslib.c,v 1.1 2014/06/01 13:30:35 obache Exp $

* for Lua 5.2 API change

--- lua/lmyoslib.c.orig	2012-06-12 06:02:01.000000000 +0000
+++ lua/lmyoslib.c
@@ -157,7 +157,11 @@ static const luaL_Reg syslib[] = {
 
 
 LUALIB_API int luaopen_myos (lua_State *L) {
+#if (LUA_VERSION_NUM >= 502)
+  luaL_newlib(L, syslib);
+#else
   luaL_register(L, LUA_OSLIBNAME, syslib);
+#endif
   return 1;
 }
 
