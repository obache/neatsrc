# $NetBSD: Makefile,v 1.55 2015/11/21 23:10:27 agc Exp $

PKGNAME=	pkg_comp-1.38
PKGREVISION=	1
CATEGORIES=	pkgtools

MAINTAINER=	jmmv@NetBSD.org
COMMENT=	Build packages inside a chroot jail
LICENSE=	modified-bsd

ONLY_FOR_PLATFORM=	NetBSD-*-*

WRKSRC=		${WRKDIR}
NO_BUILD=	YES

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

do-extract:
	${CP} ${FILESDIR}/pkg_comp.sh ${WRKSRC}/
	${CP} ${FILESDIR}/pkg_comp.8 ${WRKSRC}/

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	do-configure
SUBST_FILES.conf=	pkg_comp.sh
SUBST_VARS.conf=	MAKE PKG_INFO_CMD PKG_ADD_CMD

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_comp.sh ${DESTDIR}${PREFIX}/sbin/pkg_comp
	${INSTALL_MAN} ${WRKSRC}/pkg_comp.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/pkg_comp.8

.include "../../mk/bsd.pkg.mk"
