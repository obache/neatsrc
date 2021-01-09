# $NetBSD$

DISTNAME=	libchardet-1.0.5
CATEGORIES=	textproc
MASTER_SITES=	-${HOMEPAGE:=/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}}

HOMEPAGE=	https://github.com/Joungkyun/libchardet
COMMENT=	Mozilla's Universal Charset Detector C/C++ API
LICENSE=	mpl-1.1

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

TEST_TARGET=	test

PKGCONFIG_OVERRIDE+=	chardet.pc.in

.include "../../mk/bsd.pkg.mk"
