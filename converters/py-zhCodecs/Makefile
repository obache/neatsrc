# $NetBSD: Makefile,v 1.25 2019/04/26 13:13:46 maya Exp $

DISTNAME=	ChineseCodecs1.2.0
PKGNAME=	${PYPKGPREFIX}-zhCodecs-1.2.0
PKGREVISION=	1
CATEGORIES=	converters devel python
MASTER_SITES=	ftp://ftp.shellhung.org/pub/OpenBSD/packages/chinese/
MASTER_SITES+=	ftp://ftp2.python.or.kr/pub/FreeBSD/ports/distfiles/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/python-codecs/
COMMENT=	Python Unicode codecs for Chinese charsets

WRKSRC=		${WRKDIR}/${DISTNAME}/Python

PYTHON_VERSIONS_ACCEPTED=	27

post-extract:
	@${CHMOD} 711 ${WRKSRC}/chinesetw

EGG_NAME=	ChineseCodecs-1.1.0
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
