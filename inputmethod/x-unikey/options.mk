# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.x-unikey
PKG_SUPPORTED_OPTIONS=	gtk2
PKG_SUGGESTED_OPTIONS=	gtk2

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	gtk2

.if !empty(PKG_OPTIONS:Mgtk2)
USE_TOOLS+=	pkg-config
PLIST.gtk2=	yes
.include "../../x11/gtk2/buildlink3.mk"
GTK2_IMMODULES=	yes
.include "../../x11/gtk2/modules.mk"
CONFIGURE_ARGS+=	--with-unikey-gtk
CONFIGURE_ARGS+=	--with-gtk-sysconfdir=${WRKDIR}
TOOLS_NOOP+=	gtk-query-immodule-2.0
.else
CONFIGURE_ARGS+=	--without-unikey-gtk
.endif
