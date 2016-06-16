# $NetBSD$

DISTNAME=	accountsservice-0.6.42
CATEGORIES=	sysutils
MASTER_SITES=	http://www.freedesktop.org/software/accountsservice/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://www.freedesktop.org/wiki/Software/AccountsService/
COMMENT=	D-Bus interface for user accnout query and manipulation
LICENSE=	gnu-gpl-v3

DEPENDS+=	consolekit2-[0-9]*:../../sysutils/consolekit2
DEPENDS+=	dbus-[0-9]*:../../sysutils/dbus

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool msgfmt pkg-config

PKGCONFIG_OVERRIDE+=	src/libaccountsservice/accountsservice.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/${PKGBASE}

CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/dbus-1/system.d/org.freedesktop.Accounts.conf \
		${PKG_SYSCONFBASEDIR}/dbus-1/system.d/org.freedesktop.Accounts.conf

OWN_DIRS+=	${VARBASE}/lib/AccountsService/users
OWN_DIRS+=	${VARBASE}/lib/AccountsService/icons

BUILD_DEFS+=	VARBASE

SUBST_CLASSES+=		confpath
SUBST_STAGE.confpath=	post-configure
SUBST_FILES.confpath=	src/daemon.c
SUBST_SED.confpath+=	-e 's,/etc/gdm/custom.conf,${PKG_SYSCONFBASEDIR}/gdm/custom.conf,g'

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
