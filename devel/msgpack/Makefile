# $NetBSD: Makefile,v 1.15 2018/08/24 09:51:22 adam Exp $

DISTNAME=	msgpack-3.1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=msgpack/}
GITHUB_RELEASE=	cpp-${PKGVERSION_NOREV}
GITHUB_PROJECT=	msgpack-c

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://msgpack.org/
COMMENT=	Binary-based efficient object serialization library
LICENSE=	boost-license

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE=	msgpack.pc.in

.include "options.mk"

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE:STRING=Release
CMAKE_ARGS+=	-DMSGPACK_BUILD_EXAMPLES:BOOL=OFF

.include "../../mk/bsd.pkg.mk"
