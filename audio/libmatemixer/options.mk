# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.libmatemixer
PKG_SUPPORTED_OPTIONS=	alsa oss pulseaudio
PKG_SUGGESTED_OPTIONS=	alsa oss pulseaudio

PLIST_VARS+=	alsa oss pulse

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-alsa
PLIST.alsa=	yes
.else
CONFIGURE_ARGS+=	--disable-alsa
.endif

.if !empty(PKG_OPTIONS:Moss)
.include "../../mk/oss.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-oss
PLIST.oss=	yes
.else
CONFIGURE_ARGS+=	--disable-oss
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pulseaudio
PLIST.pulse=	yes
.else
CONFIGURE_ARGS+=	--disable-pulseaudio
.endif
