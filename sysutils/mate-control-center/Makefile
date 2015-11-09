# $NetBSD$

DISTNAME=	mate-control-center-1.12.0
CATEGORIES=	sysutils mate
MASTER_SITES=	http://pub.mate-desktop.org/releases/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	MATE Control Center
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool itstool msgfmt pkg-config xmllint

PKGCONFIG_OVERRIDE+=	capplets/keybindings/mate-keybindings.pc.in
PKGCONFIG_OVERRIDE+=	capplets/default-applications/mate-default-applications.pc.in
PKGCONFIG_OVERRIDE+=	libslab/libslab.pc.in
PKGCONFIG_OVERRIDE+=	libwindow-settings/mate-window-settings-2.0.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/${PKGBASE}

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/menus
CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/xdg/menus/matecc.menu \
		${PKG_SYSCONFDIR}/xdg/menus/matecc.menu

.include "options.mk"

ICON_THEMES=	yes

.include "../../devel/glib2/schemas.mk"

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/dconf/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.36.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/mate-menus/buildlink3.mk"
.include "../../sysutils/mate-settings-daemon/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wm/marco/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
BUILDLINK_API_DEPENDS.libXi+=	libXi>=1.2
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXxf86misc/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libmatekbd/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../x11/mate-desktop/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
