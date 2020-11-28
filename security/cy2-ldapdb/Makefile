# $NetBSD: Makefile,v 1.15 2020/01/18 21:50:34 jperkin Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-ldapdb/}
PKGREVISION=	1
COMMENT=	Cyrus SASL LDAPDB authentication plugin
SASL_PLUGIN=	yes

.include "../../security/cyrus-sasl/Makefile.common"

CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap}
CONFIGURE_ARGS+=	--enable-ldapdb

BUILD_DIRS=	common plugins

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
