# $NetBSD: options.mk,v 1.2 2010/12/16 11:52:15 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.open-vm-tools
PKG_SUPPORTED_OPTIONS=	pam x11 tests
PKG_SUGGESTED_OPTIONS=	pam x11

PLIST_VARS+=	pam tests x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpam)
PLIST.pam=	yes
MAKE_DIRS+=	/etc/pam.d
CONF_FILES+=	${EGDIR}/pam.d/vmtoolsd /etc/pam.d/vmtoolsd
.include "../../mk/pam.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mtests)
PLIST.tests=	yes
.include "../../devel/cunit/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-tests
.else
CONFIGURE_ARGS+=	--disable-tests
.endif

.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=	yes
MAKE_DIRS+=	${PKG_SYSCONFBASEDIR}/xdg/autostart
CONF_FILES+=	${EGDIR}/xdg/autostart/vmware-user.desktop ${PKG_SYSCONFBASEDIR}/xdg/autostart/vmware-user.desktop
.  include "../../devel/glib2/buildlink3.mk"
.  include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.  include "../../x11/gtk2/buildlink3.mk"
.  include "../../x11/gtkmm/buildlink3.mk"
.  include "../../x11/libICE/buildlink3.mk"
.  include "../../x11/libSM/buildlink3.mk"
.  include "../../x11/libXcomposite/buildlink3.mk"
.  include "../../x11/libXext/buildlink3.mk"
.  include "../../x11/libXi/buildlink3.mk"
.  include "../../x11/libXinerama/buildlink3.mk"
.  include "../../x11/libXrandr/buildlink3.mk"
.  include "../../x11/libXrender/buildlink3.mk"
.  include "../../x11/libXtst/buildlink3.mk"
.else
CONFIGURE_ARGS+=		--without-x
.endif
