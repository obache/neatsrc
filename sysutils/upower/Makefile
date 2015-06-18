# $NetBSD: Makefile,v 1.2 2015/03/15 16:48:17 tnn Exp $

DISTNAME=	upower-0.99.2
CATEGORIES=	sysutils
MASTER_SITES=	http://upower.freedesktop.org/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://upower.freedesktop.org
COMMENT=	Power management system message bus service
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt	# xsltproc

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config intltool xgettext msgmerge msgfmt
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-man-pages

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/${PKGBASE}
CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/UPower/UPower.conf \
		${PKG_SYSCONFDIR}/UPower/UPower.conf
CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/dbus-1/system.d/org.freedesktop.UPower.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.freedesktop.UPower.conf

OWN_DIRS+=	${VARBASE}/lib/upower
OWN_DIRS+=	${PKG_SYSCONFDIR}/UPower
MAKE_DIRS+=	${PKG_SYSCONFDIR}/dbus-1/system.d

PKGCONFIG_OVERRIDE+=	upower-glib.pc.in

BUILD_DEFS+=	VARBASE

.include "options.mk"

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.34.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus+=	dbus>=1.0
.include "../../sysutils/dbus/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.76
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
