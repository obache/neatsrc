# $NetBSD: Makefile,v 1.29 2021/05/29 19:39:00 schmonz Exp $
#

DISTNAME=	check-0.15.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libcheck/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://libcheck.github.io/check/
COMMENT=	Unit test framework for C
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
#CONFIGURE_ENV=	ac_cv_path_AWK_PATH=gawk
USE_TOOLS=	pkg-config # gawk
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE=	check.pc.in

CONFIGURE_ARGS+=	--enable-build-docs=no

TEST_TARGET=	check

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
