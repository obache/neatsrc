# $NetBSD: Makefile,v 1.8 2015/03/15 16:47:19 hiramatsu Exp $
#

DISTNAME=	msgpack-2.0.0
CATEGORIES=	devel
MASTER_SITES=	https://github.com/msgpack/msgpack-c/releases/download/cpp-${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://msgpack.org/
COMMENT=	Binary-based efficient object serialization library
LICENSE=	boost-license

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE=	msgpack.pc.in

.include "options.mk"

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE:STRING=Release

.include "../../mk/bsd.pkg.mk"
