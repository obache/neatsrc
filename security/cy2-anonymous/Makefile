# $NetBSD: Makefile,v 1.11 2018/04/17 01:57:18 christos Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-anonymous/}
COMMENT=	Cyrus SASL ANONYMOUS authentication plugin
SASL_PLUGIN=	yes

CONFLICTS=	cyrus-sasl<=2.1.19nb1

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--enable-anon

BUILD_DIRS=	common plugins

.include "../../mk/bsd.pkg.mk"
