# $NetBSD$
#
PKG_OPTIONS_VAR=	PKG_OPTIONS.capnproto
PKG_SUPPORTED_OPTIONS=	zlib openssl
PKG_SUGGESTED_OPTIONS=	zlib openssl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	${PKG_SUPPORTED_OPTIONS}

###
### Zlib support
###
.if !empty(PKG_OPTIONS:Mzlib)
.  include "../../devel/zlib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-zlib
PLIST.zlib=		yes
.else
CONFIGURE_ARGS+=	--without-zlib
.endif

###
### OpenSSL support
###
.if !empty(PKG_OPTIONS:Mopenssl)
BUILDLINK_API_DEPENDS.openssl+=	openssl>=1.1.0
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl
PLIST.openssl=		yes
.else
CONFIGURE_ARGS+=	--without-openssl
.endif
