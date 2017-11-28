# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.fcitx-unikey
PKG_SUPPORTED_OPTIONS=	qt
PKG_SUGGESTED_OPTIONS=	qt

PLIST_VARS+=	qt

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mqt)
PLIST.qt=		yes
CMAKE_ARGS+=	-DENABLE_QT:BOOL=ON
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/fcitx-qt5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.else
CMAKE_ARGS+=	-DENABLE_QT:BOOL=OFF
.endif
