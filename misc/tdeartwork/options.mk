# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.tdeartwork
PKG_SUPPORTED_OPTIONS=	arts libart opengl xscreensaver
PKG_SUGGESTED_OPTIONS=	arts libart opengl xscreensaver

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	arts libart opengl xss

.if !empty(PKG_OPTIONS:Marts)
.include "../../audio/arts/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_ARTS:BOOL=ON
PLIST.arts=	yes
.else
CMAKE_ARGS+=	-DWITH_ARTS:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mlibart)
.include "../../graphics/libart/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_LIBART:BOOL=ON
PLIST.libart=	yes
.else
CMAKE_ARGS+=	-DWITH_LIBART:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mopengl)
.include "../../graphics/MesaLib/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_OPENGL:BOOL=ON
PLIST.opengl=	yes
.else
CMAKE_ARGS+=	-DWITH_OPENGL:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mxscreensaver)
DEPENDS+=	xscreensaver-[0-9]*:../../x11/xscreensaver
CMAKE_ARGS+=	-DWITH_XSCREENSAVER:BOOL=ON
CMAKE_ARGS+=	-DWITH_ALL_INCLUDED_XSCREENSAVERS:BOOL=ON
PLIST.xss=	yes
.else
CMAKE_ARGS+=	-DWITH_XSCREENSAVER:BOOL=OFF
.endif
