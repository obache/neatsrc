# $NetBSD: Makefile,v 1.4 2019/06/24 10:59:40 nia Exp $

DISTNAME=	brise-0.38
CATEGORIES=	inputmethod chinese
MASTER_SITES=	https://github.com/rime/brise/releases/download/${DISTNAME}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rime.im/
COMMENT=	Official Rime Schema repository
LICENSE=	gnu-gpl-v3

DEPENDS+=	librime>=1.3:../../inputmethod/librime
DEPENDS+=	opencc>=1.0.2:../../converters/opencc

WRKSRC=		${WRKDIR}/brise
USE_LANGUAGES=	# none

USE_TOOLS+=	gmake bash

MAKE_ENV+=	BASH=${BASH}

MAKE_JOBS_SAFE=	no

INSTALLATION_DIRS=	share/rime-data/build
post-install:
	${INSTALL_DATA} ${WRKSRC}/output/build/*.* ${DESTDIR}${PREFIX}/share/rime-data/build

.include "../../mk/bsd.pkg.mk"
