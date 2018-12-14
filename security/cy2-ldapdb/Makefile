# $NetBSD: Makefile,v 1.14 2018/12/09 21:05:34 adam Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-ldapdb/}
COMMENT=	Cyrus SASL LDAPDB authentication plugin
SASL_PLUGIN=	yes

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap}
CONFIGURE_ARGS+=	--enable-ldapdb

BUILD_DIRS=	common plugins

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
