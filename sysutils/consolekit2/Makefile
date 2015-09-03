# $NetBSD$

DISTNAME=		ConsoleKit2-1.0.0
PKGNAME=		${DISTNAME:tl}
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=/ConsoleKit2/ConsoleKit2/releases/download/${PKGVERSION_NOREV}/}
EXTRACT_SUFX=		.tar.bz2

HOMEPAGE=	http://consolekit2.github.io/ConsoleKit2/
COMMENT=	Framework for defining and tracking users, login sessions, and seats
LICENSE=	gnu-gpl-v2

CONFLICTS+=	consolekit-[0-9]*
SUPERSEDES+=	consolekit-[0-9]*

PKG_SYSCONFSUBDIR=	ConsoleKit

EGDIR=		${PREFIX}/share/examples/consolekit
CONF_FILES+=	${EGDIR}/ConsoleKit/seats.d/00-primary.seat ${PKG_SYSCONFDIR}/seats.d/00-primary.seat
CONF_FILES+=	${EGDIR}/X11/xinit/xinitrc.d/90-consolekit ${X11BASE}/etc/X11/xinit/xinitrc.d/90-consolekit
CONF_FILES+=	${EGDIR}/dbus-1/system.d/ConsoleKit.conf ${PKG_SYSCONFBASE}/dbus-1/system.d/ConsoleKit.conf
CONF_FILES+=	${EGDIR}/logrotate.d/consolekit ${PKG_SYSCONFBASE}/logrotate.d/consolekit

OWN_DIRS+=	${PKG_SYSCONFDIR}/seats.d
OWN_DIRS+=	${PKG_SYSCONFDIR}/run-seat.d
OWN_DIRS+=	${PKG_SYSCONFDIR}/run-session.d
MAKE_DIRS+=	${PKG_SYSCONFBASE}/X11/xinit/xinitrc.d
MAKE_DIRS+=	${PKG_SYSCONFBASE}/dbus-1/system.d
MAKE_DIRS+=	${PKG_SYSCONFBASE}/logrotate.d

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		PKG_SYSCONFBASE

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config gettext-m4
USE_TOOLS+=		autoconf automake autoreconf
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}
INSTALL_MAKE_FLAGS+=	DBUS_SYS_DIR=${EGDIR}/dbus-1/system.d
INSTALL_MAKE_FLAGS+=	XINITRC_DIR=${EGDIR}/X11/xinit/xinitrc.d

.include "options.mk"

post-extract:
	${CP} ${FILESDIR}/ck-sysdeps-netbsd.c ${WRKSRC}/src/
	${CP} -rp ${WRKSRC}/tools/openbsd ${WRKSRC}/tools/netbsd

pre-configure:
	cd ${WRKSRC} && autoreconf -vi ${AUTORECONF_ARGS}

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--enable-rbac-shutdown=solaris.system.shutdown
.endif

OWN_DIRS+=	${VARBASE}/log/ConsoleKit
OWN_DIRS+=	${VARBASE}/run/ConsoleKit
CONF_FILES+=	/dev/null ${VARBASE}/log/ConsoleKit/history

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
