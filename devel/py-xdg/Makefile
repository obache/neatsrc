# $NetBSD: Makefile,v 1.10 2021/03/20 14:55:57 adam Exp $

DISTNAME=	pyxdg-0.27
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyxdg/}

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	https://freedesktop.org/wiki/Software/pyxdg
COMMENT=	Python library for XDG
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	# none

SUBST_CLASSES+=		dirspec
SUBST_STAGE.dirspec=	post-configure
SUBST_FILES.dirspec=	xdg/Menu.py xdg/BaseDirectory.py
SUBST_SED.dirspec=	-e 's,/etc/xdg,${PKG_SYSCONFBASE}/xdg,g'
SUBST_SED.dirspec+=	-e 's,/usr/local/share,${LOCALBASE}/share,g'

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
