# $NetBSD: Makefile,v 1.6 2012/10/25 06:56:07 asau Exp $
#

.include "../../textproc/mecab/Makefile.common"

DISTNAME=	mecab-jumandic-7.0-20130310
PKGNAME=	mecab-jumandic-7.0.20130310
MASTER_SITES=	-https://drive.google.com/uc?export=download&id=0B4y35FiV1wh7X2pESGlLREpxdXM

COMMENT=	Japanese Morphological Dictionary for MeCab
LICENSE=	modified-bsd

BUILD_DEPENDS+=	mecab-base-[0-9]*:../../textproc/mecab-base

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-charset=${MECAB_CHARSET:Q}

BUILD_DEFS+=		MECAB_CHARSET

UNLIMIT_RESOURCES=	datasize

FIND_PREFIX:=	MECABDIR=mecab-base
.include "../../mk/find-prefix.mk"
CONFIGURE_ARGS+=	--with-mecab-config=${MECABDIR}/bin/mecab-config

.include "../../mk/bsd.pkg.mk"
