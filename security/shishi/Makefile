# $NetBSD$
#

DISTNAME=		shishi-1.0.2
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GNU:=shishi/}

HOMEPAGE=		http://www.gnu.org/software/shishi/
COMMENT=		GNU implementation of the Kerberos 5
LICENSE=		gnu-gpl-v3

USE_TOOLS+=		msgfmt
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c
USE_LIBTOOL=		yes
INFO_FILES=	yes

PKGCONFIG_OVERRIDE+=	shishi.pc.in

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}

PKG_SYSCONFSUBDIR=	${PKGBASE}

BUILD_DEFS+=	VARBASE

OWN_DIRS_PERMS+=	${VARBASE}/${PKGBASE} ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0600

.include "options.mk"

INSTALLATION_DIRS+=	share/examples

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR} ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}
	${RM} ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/shishi.keys

.for c in shisa.conf shishi.conf shishi.skel
CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/${c} ${PKG_SYSCONFDIR}/${c}
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libgcrypt-prefix=${BUILDLINK_PREFIX.libgcrypt}
.include "../../security/libtasn1/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libtasn1-prefix=${BUILDLINK_PREFIX.libtasn1}
.include "../../mk/bsd.pkg.mk"
