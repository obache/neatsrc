# $NetBSD: Makefile,v 1.10 2017/09/04 18:08:27 wiz Exp $
#

DISTNAME=	py-smbpasswd-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py-//}
CATEGORIES=	security
MASTER_SITES=	http://barryp.org/static/software/download/py-smbpasswd/1.0.1/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://barryp.org/software/py-smbpasswd/
COMMENT=	Python SMB Password Hash Generator

EGG_NAME?=	${DISTNAME:S/py-//:C/-([^0-9])/_\1/g}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
