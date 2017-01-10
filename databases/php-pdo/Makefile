# $NetBSD: Makefile,v 1.14 2015/12/06 13:51:30 taca Exp $

MODNAME=		pdo
CATEGORIES+=		databases
COMMENT=		PHP extension for PHP Data Objects (base)

USE_PHP_EXT_PATCHES=	yes

.include "../../mk/bsd.prefs.mk"

.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}

PLIST_VARS+=		pdo_error

.if ${PKG_PHP_VERSION} != "55"
PLIST.pdo_error=	yes
.endif

.include "../../mk/bsd.pkg.mk"
