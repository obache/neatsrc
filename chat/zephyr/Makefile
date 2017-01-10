# $NetBSD$

DISTNAME=	zephyr-3.1.2
CATEGORIES=	chat
MASTER_SITES=	-https://github.com/zephyr-im/zephyr/archive/release/${PKGVERSION_NOREV}.tar.gz

HOMEPAGE=	http://zephyr-im.org/
COMMENT=	Project Athena Zephyr notification system
#LICENSE=	# not a mit license

WRKSRC=		${WRKDIR}/${DISTNAME:S/-/-release-/}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

PKGCONFIG_OVERRIDE+=	zephyr.pc.in

CONFIGURE_ARGS+=	--with-krb5=${KRB5BASE}
CONFIGURE_ARGS+=	--without-krb4
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
PKG_SYSCONFSUBDIR=	${PKGBASE}
OWN_DIRS+=		${PKG_SYSCONFBASEDIR}/${PKGBASE}/acl

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples

CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/default.subscriptions \
		${PKG_SYSCONFDIR}/default.subscriptions

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
