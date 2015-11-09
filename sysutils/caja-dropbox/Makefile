# $NetBSD$

DISTNAME=	caja-dropbox-1.12.0
CATEGORIES=	sysutils mate
MASTER_SITES=	http://pub.mate-desktop.org/releases/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	Dropbox Caja extension
LICENSE=	cc-by-nd-v3.0-license AND gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2
DEPENDS+=	${PYPKGPREFIX}-gobject-[0-9]*:../../devel/py-gobject
DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

ICON_THEMES=	yes

REPLACE_PYTHON=	caja-dropbox.in

.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/caja/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
