# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.tdeaartwork
PKG_SUPPORTED_OPTIONS=	xscreensaver
PKG_SUGGESTED_OPTIONS=	xscreensaver

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mxscreensaver)
DEPENDS+=	xscreensaver-[0-9]*:../../x11/xscreensaver
CMAKE_ARGS+=	-DWITH_XSCREENSAVER:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_XSCREENSAVER:BOOL=OFF
.endif
