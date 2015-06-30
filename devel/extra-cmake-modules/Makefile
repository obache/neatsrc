# $NetBSD$

DISTNAME=	extra-cmake-modules-5.11.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://projects.kde.org/projects/kdesupport/extra-cmake-modules
COMMENT=	Extrac CMake modules
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DBUILD_TESTING:BOOL=OFF
CMAKE_ARGS+=	-DSPHINX_EXECUTABLE:PATH=${PREFIX}/bin/sphinx-build${PYVERSSUFFIX}
CMAKE_ARGS+=	-DMAN_INSTALL_DIR:PATH=${PKGMANDIR}

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
