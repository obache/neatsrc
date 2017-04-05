# $NetBSD: Makefile,v 1.63 2017/02/12 06:26:05 ryoon Exp $

DISTNAME=	gDeskCal-0_57_1
PKGNAME=	gdeskcal-0.57.1
PKGREVISION=	31
CATEGORIES=	time
MASTER_SITES=	http://www.pycage.de/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pycage.de/\#gdeskcal
COMMENT=	Desktop calendar

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2

WRKSRC=		${WRKDIR}/gDeskCal-0.57.1
NO_BUILD=	yes

REPLACE_PYTHON=	gdeskcal

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-gtk2

INSTALLATION_DIRS=	bin lib/gdeskcal

post-extract:
	${RM} ${WRKSRC}/data/format.xml~

do-install:
	(cd ${WRKSRC} && ${CP} -r . ${DESTDIR}${PREFIX}/lib/gdeskcal)
	${PY_COMPILE_ALL} ${DESTDIR}${PREFIX}/lib/gdeskcal/code
	${LN} -s ../lib/gdeskcal/gdeskcal ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
