# $NetBSD$

DISTNAME=	mate-user-share-1.10.0
CATEGORIES=	sysutils www mate
MASTER_SITES=	http://pub.mate-desktop.org/releases/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	obache@users.sourceforge.net
HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	MATE user-leve file shareing
LICENSE=	gnu-gpl-v2

DEPENDS+=	${APACHE_PKG_PREFIX}-dnssd>=0.6:../../www/ap22-dnssd
TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2 # for xmllint

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--with-httpd=${BUILDLINK_PREFIX.apache}/sbin/httpd
CONFIGURE_ARGS+=	--with-modules-path=${BUILDLINK_PREFIX.apache}/lib/httpd

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/${PKGBASE}

MAKE_DIRS+=	${PKG_SYSCONFBASEDIR}/xdg/autostart
CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/xdg/autostart/mate-user-share-obexftp.desktop \
		${PKG_SYSCONFBASEDIR}/xdg/autostart/mate-user-share-obexftp.desktop
CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/xdg/autostart/mate-user-share-obexpush.desktop \
		${PKG_SYSCONFBASEDIR}/xdg/autostart/mate-user-share-obexpush.desktop
CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/xdg/autostart/mate-user-share-webdav.desktop \
		${PKG_SYSCONFBASEDIR}/xdg/autostart/mate-user-share-webdav.desktop

.include "../../devel/glib2/schemas.mk"

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/caja/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus+=	dbus>=1.1.1
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
