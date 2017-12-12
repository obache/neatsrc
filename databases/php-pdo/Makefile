# $NetBSD: Makefile,v 1.15 2017/12/09 02:25:35 taca Exp $

MODNAME=		pdo
CATEGORIES+=		databases
COMMENT=		PHP extension for PHP Data Objects (base)

USE_PHP_EXT_PATCHES=	yes

.include "../../mk/bsd.prefs.mk"

.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}

.include "../../mk/bsd.pkg.mk"
