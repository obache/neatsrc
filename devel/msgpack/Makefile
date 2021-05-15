# $NetBSD: Makefile,v 1.19 2021/02/14 18:56:11 adam Exp $

DISTNAME=	msgpack-3.3.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=msgpack/}
GITHUB_PROJECT=	msgpack-c
GITHUB_RELEASE=	cpp-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://msgpack.org/
COMMENT=	Binary-based efficient object serialization library
LICENSE=	boost-license

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE=	msgpack.pc.in

.include "options.mk"

CMAKE_ARGS+=	-DMSGPACK_BUILD_EXAMPLES:BOOL=OFF

.include "../../mk/bsd.pkg.mk"
