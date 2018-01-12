# $NetBSD: Makefile,v 1.10 2018/01/10 10:05:17 jdolecek Exp $

MODNAME=	apcu
PECL_VERSION=	5.1.9
CATEGORIES+=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	APCu - APC User Cache
LICENSE=	php

PHP_VERSIONS_ACCEPTED=	70 71 72

CONFIGURE_ARGS+=	--enable-${MODNAME}

PLIST_SUBST+=		PKGBASE=${PKGBASE:Q}

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${DOCDIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
