# $NetBSD: Makefile,v 1.11 2014/01/25 10:30:31 wiz Exp $

DISTNAME=	python-xlib-0.21
PKGNAME=	${PYPKGPREFIX}-Xlib-0.21
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-xlib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ccatrian@eml.cc
HOMEPAGE=	https://github.com/python-xlib/python-xlib/
COMMENT=	Functional X client library for Python
LICENSE=	gnu-lgpl-v2

DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm:../../devel/py-setuptools_scm

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
