# $NetBSD$

DISTNAME=	cangjie-1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	inputmethod chinese python
MASTER_SITES=	https://github.com/Cangjians/pycangjie/releases/download/v${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://cangjians.github.io/projects/pycangjie/
COMMENT=	Python wrapper to libcangjie
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-cython>=0.1.4:../../devel/py-cython

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	gmake pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	27
PY_PATCHPLIST=	yes

CONFIGURE_ENV+=	CYTHON=${LOCALBASE}/bin/cython${PYVERSSUFFIX}

.include "../../inputmethod/libcangjie/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
