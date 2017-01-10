# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.zeromq
PKG_SUPPORTED_OPTIONS=	gssapi pgm
PKG_SUGGESTED_OPTIONS=	gssapi pgm

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgssapi)
CONFIGURE_ARGS+=	--with-libgssapi_krb5
.include "../../mk/krb5.buildlink3.mk"
.  if !empty(KRB5_TYPE:Mheimdal)
BUILDLINK_TRANSFORM+=	l:gssapi_krb5:gssapi
.  endif
.else
CONFIGURE_ARGS+=	--with-libgssapi_krb5=no
.endif

.if !empty(PKG_OPTIONS:Mpgm)
CONFIGURE_ARGS+=	--with-pgm
.include "../../net/openpgm/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-pgm=no
.endif
