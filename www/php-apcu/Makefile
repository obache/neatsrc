# $NetBSD: Makefile,v 1.14 2019/10/22 08:25:59 taca Exp $

MODNAME=	apcu
PECL_VERSION=	5.1.17
CATEGORIES+=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	APCu - APC User Cache
LICENSE=	php

PHP_VERSIONS_ACCEPTED=	71 72 73

CONFIGURE_ARGS+=	--enable-${MODNAME}

PLIST_SUBST+=		PKGBASE=${PKGBASE:Q}

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${DOCDIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
