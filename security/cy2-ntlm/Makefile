# $NetBSD: Makefile,v 1.29 2018/04/17 01:57:18 christos Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-ntlm/}
COMMENT=	Cyrus SASL NTLM authentication plugin
SASL_PLUGIN=	yes

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--enable-ntlm
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}

BUILD_DIRS=	common plugins

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
