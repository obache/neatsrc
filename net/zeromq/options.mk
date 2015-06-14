# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.zeromq
PKG_SUPPORTED_OPTIONS=	pgm
PKG_SUGGESTED_OPTIONS=	pgm

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpgm)
CONFIGURE_ARGS+=	--with-system-pgm
.include "../../net/openpgm/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-pgm=no
CONFIGURE_ARGS+=	--with-system-pgm=no
.endif
