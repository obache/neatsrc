# $NetBSD: Makefile,v 1.5 2012/10/25 06:56:09 asau Exp $
#

DISTNAME=	onig-5.9.6
PKGNAME=	${DISTNAME:S/onig/oniguruma/}
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/kkos/oniguruma/releases/download/v${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kkos/oniguruma/
COMMENT=	Regular expressions library
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

TEST_TARGET=	atest

PKGCONFIG_OVERRIDE+=	oniguruma.pc.in

.include "../../mk/bsd.pkg.mk"
