# $NetBSD: Makefile,v 1.19 2018/12/09 21:05:34 adam Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-login/}
COMMENT=	Cyrus SASL LOGIN authentication plugin
SASL_PLUGIN=	yes

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--enable-login

BUILD_DIRS=	common plugins

.include "../../mk/bsd.pkg.mk"
