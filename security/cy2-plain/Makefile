# $NetBSD: Makefile,v 1.12 2018/12/09 21:05:35 adam Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-plain/}
COMMENT=	Cyrus SASL PLAIN authentication plugin
SASL_PLUGIN=	yes

CONFLICTS=	cyrus-sasl<=2.1.19nb1

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--enable-plain

BUILD_DIRS=	common plugins

.include "../../mk/bsd.pkg.mk"
