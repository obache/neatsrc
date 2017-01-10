# $NetBSD$

DISTNAME=	uvconv-1.1.3b
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=unikey/}

HOMEPAGE=	http://www.unikey.org/linux.php
COMMENT=	Universal command-line Vietnames encoding converter
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/uvconv
USE_LANGUAGES=	c++
USE_TOOLS+=	gmake

BUILD_DIRS=	uvconvert

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uvconvert/uvconv ${DESTDIR}${PREFIX}/bin/uvconv
	${INSTALL_MAN} ${WRKSRC}/uvconv.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/uvconv.1

.include "../../mk/bsd.pkg.mk"
