# $NetBSD: Makefile,v 1.24 2017/01/01 14:43:53 wiz Exp $

DISTNAME=	ZSI-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pywebsvcs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pywebsvcs.sourceforge.net/
COMMENT=	SOAP implementation

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

USE_LANGUAGES=	# none

post-extract:
	${MV} ${WRKSRC}/scripts/wsdl2py \
		${WRKSRC}/scripts/wsdl2py${PYVERSSUFFIX}
	${MV} ${WRKSRC}/scripts/wsdl2dispatch \
		${WRKSRC}/scripts/wsdl2dispatch${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
