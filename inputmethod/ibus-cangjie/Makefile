# $NetBSD$

DISTNAME=	ibus-cangjie-2.4
CATEGORIES=	inputmethod chinese
MASTER_SITES=	https://github.com/Cangjians/ibus-cangjie/releases/download/v${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://cangjians.github.io/projects/ibus-cangjie/
COMMENT=	IBus engine for users of the Cangjie and Quick input methods
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-cangjie-[0-9]*:../../inputmethod/py-cangjie

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	gmake pkg-config intltool msgfmt
USE_PKGLOCALEDIR=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27
PY_PATCHPLIST=	yes

ICON_THEMES=	yes

.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../inputmethod/libcangjie/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
