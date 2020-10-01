# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.arts
PKG_SUPPORTED_OPTIONS=		alsa audiofile esound mad jack vorbis sndio
PKG_SUGGESTED_OPTIONS=		audiofile mad vorbis
PKG_SUGGESTED_OPTIONS.Linux=	alsa
PKG_SUGGESTED_OPTIONS.OpenBSD=	sndio

.include "../../mk/bsd.options.mk"

# ALSA support
.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_ALSA:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_ALSA:BOOL=OFF
.endif

# AUDIOFILE support
.if !empty(PKG_OPTIONS:Maudiofile)
.include "../../audio/libaudiofile/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_AUDIOFILE:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_AUDIOFILE:BOOL=OFF
.endif

# ESOUND support
.if !empty(PKG_OPTIONS:Mesound)
.include "../../audio/esound/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_ESOUND:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_ESOUND:BOOL=OFF
.endif

# JACK support
.if !empty(PKG_OPTIONS:Mjack)
.include "../../audio/jack/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_JACK:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_JACK:BOOL=OFF
.endif

# MAD support
.if !empty(PKG_OPTIONS:Mmad)
.include "../../audio/libmad/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_MAD:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_MAD:BOOL=OFF
.endif

# Ogg/Vorbis support
.if !empty(PKG_OPTIONS:Mvorbis)
.include "../../audio/libvorbis/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_VORBIS:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_VORBIS:BOOL=OFF
.endif

# SNDIO support
.if !empty(PKG_OPTIONS:Msndio)
CMAKE_ARGS+=	-DWITH_SNDIO:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_SNDIO:BOOL=OFF
.endif
