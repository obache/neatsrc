# $NetBSD$
#

DISTNAME=	onigmo-6.1.1
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/k-takata/Onigmo/releases/download/Onigmo-${PKGVERSION_NOREV}/

HOMEPAGE=	https://github.com/k-takata/Onigmo/
COMMENT=	Regular expressions library
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

TEST_TARGET=	atest

PKGCONFIG_OVERRIDE+=	onigmo.pc.in

.include "../../mk/bsd.pkg.mk"
