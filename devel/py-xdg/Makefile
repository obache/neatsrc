# $NetBSD: Makefile,v 1.5 2014/01/27 19:00:18 wiz Exp $

DISTNAME=	pyxdg-0.25
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	http://people.freedesktop.org/~takluyver/

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://freedesktop.org/wiki/Software/pyxdg
COMMENT=	Python library for XDG
LICENSE=	gnu-lgpl-v2

SUBST_CLASSES+=		dirspec
SUBST_STAGE.dirspec=	post-configure
SUBST_FILES.dirspec=	xdg/Menu.py xdg/BaseDirectory.py
SUBST_SED.dirspec=	-e 's,/etc/xdg,${PKG_SYSCONFBASE}/xdg,g'
SUBST_SED.dirspec+=	-e 's,/usr/local/share,${LOCALBASE}/share,g'

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
