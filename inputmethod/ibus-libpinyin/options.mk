# $NetBSD: options.mk,v 1.1 2014/06/01 13:30:35 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.ibus-libpinyin
PKG_SUPPORTED_OPTIONS=	lua opencc cloud-input
PKG_SUGGESTED_OPTIONS=	lua

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	lua

#
# Lua extension
#
.if !empty(PKG_OPTIONS:Mlua)
.include "../../lang/lua/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-lua-extension
PLIST.lua=		yes
.else
CONFIGURE_ARGS+=	--disable-lua-extension
.endif

#
# OpenCC
#
.if !empty(PKG_OPTIONS:Mopencc)
.include "../../converters/opencc/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-opencc
.else
CONFIGURE_ARGS+=	--disable-opencc
.endif

#
# cloud input
#
.if !empty(PKG_OPTIONS:Mcloud-input)
.include "../../net/libsoup/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-cloud-input-mode
.else
CONFIGURE_ARGS+=	--disable-cloud-input-mode
.endif
