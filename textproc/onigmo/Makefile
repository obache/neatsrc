# $NetBSD$
#

DISTNAME=	Onigmo-5.15.0
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/k-takata/Onigmo/archive/

HOMEPAGE=	https://github.com/k-takata/Onigmo/
COMMENT=	Regular expressions library
LICENSE=	2-clause-bsd

CONFLICTS+=	oniguruma-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

TEST_TARGET=	atest

PKGCONFIG_OVERRIDE+=	oniguruma.pc.in

WRKSRC=		${WRKDIR}/Onigmo-${DISTNAME}

.include "../../mk/bsd.pkg.mk"
