# $NetBSD: Makefile,v 1.6 2017/06/20 15:22:05 youri Exp $

GHCOMMIT=	1b023cb9a21d533cdcd567ad73cc9b43ef00a1b3
DISTNAME=	${GHCOMMIT}
PKGNAME=	elementary-xfce-icon-theme-0.8
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
