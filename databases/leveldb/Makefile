# $NetBSD: Makefile,v 1.3 2021/02/20 13:45:35 ryoon Exp $

DISTNAME=	leveldb-1.22
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	https://github.com/google/leveldb
COMMENT=	Fast and lightweight key/value database library by Google
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_LANGUAGES+=	c c++11
CMAKE_ARGS+=	-DLEVELDB_BUILD_BENCHMARKS=OFF
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON
CMAKE_ARGS+=	-DTHREADS_PREFER_PTHREAD_FLAG:BOOL=ON
CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=ON
TEST_TARGET=	test

.include "../../devel/snappy/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
