# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.mate-control-center
PKG_SUPPORTED_OPTIONS=	appindicator
PKG_SUGGESTED_OPTIONS=	appindicator

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	appindicator

.if !empty(PKG_OPTIONS:Mappindicator)
.include "../../devel/libappindicator/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-appindicator
PLIST.appindicator=	yes
.else
CONFIGURE_ARGS+=	--disable-appindicator
.endif
