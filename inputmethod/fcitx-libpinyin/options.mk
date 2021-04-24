# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.fcitx-libpinyin
PKG_SUPPORTED_OPTIONS=	qt
PKG_SUGGESTED_OPTIONS=	#qt

PLIST_VARS+=	qt

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt)
PLIST.qt=		yes
CMAKE_ARGS+=	-DENABLE_QT:BOOL=ON
.include "../../inputmethod/fcitx-qt5/buildlink3.mk"
# TODO: missing qt5-qtwebengine
.else
CMAKE_ARGS+=	-DENABLE_QT:BOOL=OFF
.endif
