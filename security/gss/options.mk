# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.gss
PKG_SUPPORTED_OPTIONS=	kerberos
PKG_SUGGESTED_OPTIONS=	kerberos

.include "../../mk/bsd.options.mk"

# Package-specific option-handling

PLIST_VARS+=	krb5

###
### kerberos support
###
.if !empty(PKG_OPTIONS:Mkerberos)
.include "../../security/shishi/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-kerberos5
CONFIGURE_ARGS+=	--with-libshishi-prefix=${BUILDLINK_PREFIX.shishi}
PLIST.krb5=		yes
.else
CONFIGURE_ARGS+=	--disable-kerberos5
.endif
