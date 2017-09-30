# $NetBSD$

DISTNAME=	brotli-1.0.1
CATEGORIES=	archivers
MASTER_SITES=	-https://github.com/google/brotli/archive/v${PKGVERSION_NOREV}${EXTRACT_SUFX}

HOMEPAGE=	https://github.com/google/${PKGBASE}/
COMMENT=	generic-purpose lossless compression algorithm.
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libbrotlicommon.pc
PKGCONFIG_OVERRIDE+=	libbrotlidec.pc
PKGCONFIG_OVERRIDE+=	libbrotlienc.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

CMAKE_ARGS+=	-DCMAKE_SHARED_LINKER_FLAGS=${COMPILER_RPATH_FLAG}${PREFIX}/lib
CMAKE_ARGS+=	-DCMAKE_EXE_LINKER_FLAGS=${COMPILER_RPATH_FLAG}${PREFIX}/lib

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/brotli.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
