# $NetBSD: Makefile,v 1.14 2016/07/09 06:39:08 wiz Exp $
#

DISTNAME=	libical-2.0.0
CATEGORIES=	time
MASTER_SITES=	https://github.com/libical/libical/releases/download/v${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libical.github.io/libical
COMMENT=	Implementation of iCalendar protocols and data formats
LICENSE=	gnu-lgpl-v2.1 OR mpl-1.0

USE_TOOLS+=	perl
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DUSE_BUILTIN_TZDATA=false

PKGCONFIG_OVERRIDE+=	libical.pc.in

TEST_TARGET=	test

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
