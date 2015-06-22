# $NetBSD$

DISTNAME=	mozo-1.10.0
CATEGORIES=	x11 mate
MASTER_SITES=	http://pub.mate-desktop.org/releases/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	obache@users.sourceforge.net
HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	Menu editor for MATE
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-gobject>=2.15.1:../../devel/py-gobject
DEPENDS+=	${PYPKGPREFIX}-gtk2>=2.13.0:../../x11/py-gtk2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake intltool msgfmt pkg-config

PY_PATCHPLIST=	yes

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/mate-menus/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
