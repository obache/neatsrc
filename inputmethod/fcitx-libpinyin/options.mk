# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.fcitx-libpinyin
PKG_SUPPORTED_OPTIONS=	qt
PKG_SUGGESTED_OPTIONS=	qt

PLIST_VARS+=	qt

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt)
USE_FCITX_QT_GUI=	yes
PLIST.qt=		yes
CMAKE_ARGS+=	-DENABLE_QT:BOOL=ON
.else
CMAKE_ARGS+=	-DENABLE_QT:BOOL=OFF
.endif
