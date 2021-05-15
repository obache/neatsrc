# $NetBSD: Makefile,v 1.4 2021/02/20 13:56:07 ryoon Exp $

DISTNAME=	OpenCC-ver.1.1.2
PKGNAME=	${DISTNAME:S/-ver./-/:tl}
CATEGORIES=	converters chinese
MASTER_SITES=	-https://github.com/BYVoid/OpenCC/archive/ver.${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://opencc.byvoid.com/
COMMENT=	Convertion between Traditional and Simplified Chinese
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${DISTNAME} # GitHub rule is not relevant for this.

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	opencc.pc.in

USE_GCC_RUNTIME=	yes

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE:STRING=Release
CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH:STRING=${PREFIX}/lib
CMAKE_ARGS+=	-DUSE_SYSTEM_MARISA:BOOL=ON

TEST_TARGET=	test

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/tool.mk"
.include "../../textproc/marisa/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
