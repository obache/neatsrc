# $NetBSD: Makefile,v 1.7 2016/11/05 14:37:21 jdolecek Exp $

MODNAME=	apcu
PECL_VERSION=	5.1.7
CATEGORIES+=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	APCu - APC User Cache
LICENSE=	php

PHP_VERSIONS_ACCEPTED=	70 71

CONFIGURE_ARGS+=	--enable-${MODNAME}

PLIST_SUBST+=		PKGBASE=${PKGBASE:Q}

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${DOCDIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
