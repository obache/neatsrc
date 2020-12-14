# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.tdeaccessibility
PKG_SUPPORTED_OPTIONS=	alsa

PKG_SUGGESTED_OPTIONS.Linux+=	alsa

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	alsa

# Enable ALSA support
.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-alsa
.else
CONFIGURE_ARGS+=	--without-alsa
.endif
