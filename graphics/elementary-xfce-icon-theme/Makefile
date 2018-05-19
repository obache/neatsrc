# $NetBSD: Makefile,v 1.7 2018/05/15 21:30:55 youri Exp $

GHCOMMIT=	9efbd4a14cbae1a8b05536afff262b67ead6d33e
DISTNAME=	${GHCOMMIT}
PKGNAME=	elementary-xfce-icon-theme-0.11
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
