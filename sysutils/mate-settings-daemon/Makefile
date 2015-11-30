# $NetBSD$

DISTNAME=	mate-settings-daemon-1.12.1
CATEGORIES=	sysutils mate
MASTER_SITES=	http://pub.mate-desktop.org/releases/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://www.mate-desktop.org/releases/
COMMENT=	MATE settings daemon
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

PKGCONFIG_OVERRIDE+=	data/mate-settings-daemon.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "options.mk"

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/mate-settings-daemon

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
OWN_DIRS+=	${PKG_SYSCONFDIR}/mate-settings-daemon/xrandr
CONF_FILES+=	${PREFIX}/share/examples/mate-settings-daemon/xdg/autostart/mate-settings-daemon.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/mate-settings-daemon.desktop
OWN_DIRS+=	${PKG_SYSCONFDIR}/xrdb
.for ad in Editres Emacs General Motif Tk Xaw
CONF_FILES+=	${PREFIX}/share/examples/mate-settings-daemon/xrdb/${ad}.ad \
		${PKG_SYSCONFDIR}/xrdb/${ad}.ad
.endfor

ICON_THEMES=	yes

.include "../../devel/glib2/schemas.mk"

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.36.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/dconf/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus+=	dbus>=1.1.2
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/kbproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXxf86misc/buildlink3.mk"
.include "../../x11/libmatekbd/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
