# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.shishi
PKG_SUPPORTED_OPTIONS=	pam inet6 tls idn
PKG_SUGGESTED_OPTIONS=	pam inet6 tls idn

.include "../../mk/bsd.options.mk"

# Package-specific option-handling

PLIST_VARS+=	pam

###
### PAM support
###
.if !empty(PKG_OPTIONS:Mpam)
.include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pam
PLIST.pam=	yes
.else
CONFIGURE_ARGS+=	--disable-pam
.endif

###
### IPv6 support
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

###
### IDN support
###
.if !empty(PKG_OPTIONS:Midn)
.include "../../devel/libidn/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libidn-prefix=${BUILDLINK_PREFIX.libidn}
.else
CONFIGURE_ARGS+=	--without-stringprep
.endif

###
### TLS support
###
.if !empty(PKG_OPTIONS:Mtls)
.include "../../security/gnutls/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libgnutls-prefix=${BUILDLINK_PREFIX.gnutls}
.else
CONFIGURE_ARGS+=	--disable-starttls
.endif
