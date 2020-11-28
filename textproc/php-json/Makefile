# $NetBSD: Makefile,v 1.8 2020/03/22 21:21:32 joerg Exp $

MODNAME=		json
CATEGORIES+=		textproc
COMMENT=		PHP extension for JSON serialization support

BUILD_DEPENDS+=	re2c>=0.13.0.4:../../devel/re2c

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared

.include "../../lang/php/ext.mk"

MAKE_ENV+=		RE2C=re2c

.include "../../mk/bsd.pkg.mk"
