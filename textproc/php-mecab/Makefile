# $NetBSD: Makefile,v 1.12 2016/11/27 14:55:30 taca Exp $
#

PECL_DISTNAME=	${MODNAME}-${PECL_VERSION}
MODNAME=	mecab
PECL_VERSION=	0.6.0
PKGREVISION=	1
CATEGORIES=	textproc japanese
MASTER_SITES=   http://pecl.opendogs.org/get/
#EXTRACT_SUFX=	.tar.gz

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/rsky/php-mecab
COMMENT=	PHP extension for MeCab Morphological Analyzer
LICENSE=	mit

EGDIR=		${PREFIX}/share/examples/php

INSTALLATION_DIRS+=	${EGDIR}/mecab

post-install:
	cd ${WRKSRC}/examples && \
	${INSTALL_DATA} *.php ${DESTDIR}${EGDIR}/mecab

.include "../../textproc/mecab-base/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
