# $NetBSD$

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-otp/}
COMMENT=	Cyrus SASL SRP authentication plugin
SASL_PLUGIN=	yes

CONFLICTS=	cyrus-sasl<=2.1.19nb1

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--enable-srp
CONFIGURE_ARGS+=	--enable-srp-setpas
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}

BUILD_DIRS=	common plugins

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
