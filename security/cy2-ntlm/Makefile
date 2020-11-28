# $NetBSD: Makefile,v 1.31 2020/01/18 21:50:34 jperkin Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-ntlm/}
PKGREVISION=	1
COMMENT=	Cyrus SASL NTLM authentication plugin
SASL_PLUGIN=	yes

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--enable-ntlm
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}

BUILD_DIRS=	common plugins

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
