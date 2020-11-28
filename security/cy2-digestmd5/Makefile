# $NetBSD: Makefile,v 1.23 2020/01/18 21:50:34 jperkin Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-digestmd5/}
PKGREVISION=	1
COMMENT=	Cyrus SASL DIGEST-MD5 authentication plugin
SASL_PLUGIN=	yes

CONFLICTS=	cyrus-sasl<=2.1.19nb1

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--enable-digest
CONFIGURE_ARGS+=	--with-rc4
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}

BUILD_DIRS=	common plugins

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
