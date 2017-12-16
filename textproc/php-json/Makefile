# $NetBSD: Makefile,v 1.5 2017/12/13 11:42:41 jperkin Exp $

MODNAME=		json
PKGREVISION=		1
CATEGORIES+=		textproc
COMMENT=		PHP extension for JSON serialization support

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
