# $NetBSD$

DISTNAME=	mozo-1.14.0
CATEGORIES=	x11 mate
MASTER_SITES=	http://pub.mate-desktop.org/releases/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	Menu editor for MATE
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	gtk3+-[0-9]*:../../x11/gtk3

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake intltool msgfmt pkg-config

ICON_THEMES=	yes

PY_PATCHPLIST=	yes

.include "../../devel/py-gobject3/buildlink3.mk"
.include "../../sysutils/mate-menus/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
