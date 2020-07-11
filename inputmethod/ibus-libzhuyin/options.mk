# $NetBSD$
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.ibus-libzhuyin
PKG_SUPPORTED_OPTIONS=	opencc

.include "../../mk/bsd.options.mk"

#
# OpenCC
#
.if !empty(PKG_OPTIONS:Mopencc)
.include "../../converters/opencc/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-opencc
.else
CONFIGURE_ARGS+=	--disable-opencc
.endif
