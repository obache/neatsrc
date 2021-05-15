# $NetBSD: Makefile,v 1.7 2021/03/07 13:42:44 taca Exp $

MODNAME=		mbstring
CATEGORIES+=		converters
COMMENT=		PHP extension for multibyte characters support
LICENSE=		php

CONFLICTS=		php-mbstring-[0-9]*

PLIST_VARS+=		php7

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.if ${PKG_PHP_VERSION} >= 74
.include "../../textproc/oniguruma/buildlink3.mk"
.endif
.if ${PKG_PHP_MAJOR_VERS} < 8
PLIST.php7=	yes
.endif
.include "../../mk/bsd.pkg.mk"
