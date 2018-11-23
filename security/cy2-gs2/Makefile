# $NetBSD$

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-gs2/}
COMMENT=	Cyrus SASL GS2 authentication plugin
SASL_PLUGIN=	yes

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--enable-gssapi=${KRB5BASE:Q}
CONFIGURE_ARGS+=	--with-gss_impl=${GSSIMPL.${KRB5_TYPE}}
GSSIMPL.heimdal=	heimdal
GSSIMPL.mit-krb5=	mit

BUILD_DIRS=	common plugins

MAKE_FLAGS+=	plugin_LTLIBRARIES=libgs2.la

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
