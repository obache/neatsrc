# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.fcitx-configtool
PKG_SUPPORTED_OPTIONS=	gtk2 gtk3
PKG_SUGGESTED_OPTIONS=	gtk2 gtk3

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gtk2 gtk3

.if !empty(PKG_OPTIONS:Mgtk2)
PLIST.gtk2=		yes
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_GTK2:BOOL=ON
.else
CMAKE_ARGS+=	-DENABLE_GTK2:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Mgtk3)
PLIST.gtk3=		yes
.include "../../x11/gtk3/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_GTK3:BOOL=ON
.else
CMAKE_ARGS+=	-DENABLE_GTK3:BOOL=OFF
.endif
