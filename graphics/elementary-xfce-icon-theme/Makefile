# $NetBSD: Makefile,v 1.5 2016/02/26 14:01:09 jperkin Exp $

GHCOMMIT=	a0b2b19231c3383f77f106d9cdacb2d148519cfd
DISTNAME=	${GHCOMMIT}
PKGNAME=	elementary-xfce-icon-theme-0.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=shimmerproject/elementary-xfce/archive/}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/shimmerproject/elementary-xfce
COMMENT=	Elementary icons forked, extended and maintained for Xfce
LICENSE=	gnu-gpl-v2

NO_BUILD=	YES
USE_LANGUAGES=	# none, not even C
USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}/elementary-xfce-${GHCOMMIT}

INSTALLATION_DIRS+=	share/icons

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pm e* ${DESTDIR}${PREFIX}/share/icons/

.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
