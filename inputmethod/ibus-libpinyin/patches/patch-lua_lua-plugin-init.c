$NetBSD$

* for Lua 5.2 API change

--- lua/lua-plugin-init.c.orig	2014-12-09 05:20:30.000000000 +0000
+++ lua/lua-plugin-init.c
@@ -425,7 +425,11 @@ static const luaL_Reg imelib[] = {
 };
 
 LUALIB_API int luaopen_ime (lua_State *L) {
+#if LUA_VERSION_NUM >= 502
+  luaL_newlib(L, imelib);
+#else
   luaL_register(L, LUA_IMELIBNAME, imelib);
+#endif
   return 1;
 }
 
