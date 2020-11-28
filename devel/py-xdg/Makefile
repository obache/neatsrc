# $NetBSD: Makefile,v 1.7 2020/03/25 11:30:48 nia Exp $

DISTNAME=	pyxdg-0.26
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyxdg/}

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	https://freedesktop.org/wiki/Software/pyxdg
COMMENT=	Python library for XDG
LICENSE=	gnu-lgpl-v2

SUBST_CLASSES+=		dirspec
SUBST_STAGE.dirspec=	post-configure
SUBST_FILES.dirspec=	xdg/Menu.py xdg/BaseDirectory.py
SUBST_SED.dirspec=	-e 's,/etc/xdg,${PKG_SYSCONFBASE}/xdg,g'
SUBST_SED.dirspec+=	-e 's,/usr/local/share,${LOCALBASE}/share,g'

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
