# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.tdeaccessibility
PKG_SUPPORTED_OPTIONS=	alsa

.if !empty(PKG_BUILD_OPTIONS.tdelibs:Marts)
PKG_SUPPORTED_OPTIONS+=	arts
PKG_SUGGESTED_OPTIONS+=	arts
.endif

PKG_SUGGESTED_OPTIONS.Linux+=	arts alsa


.include "../../mk/bsd.options.mk"

PLIST_VARS+=	arts alsa

# Enable ALSA support
.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_ALSA:BOOL=ON
PLIST.alsa=	yes
.else
CMAKE_ARGS+=	-DWITH_ALSA:BOOL=OFF
.endif

.if !empty(PKG_OPTIONS:Marts)
.  include "../../multimedia/tdemultimedia/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_ARTS:BOOL=ON
PLIST.arts=	yes
.else
CMAKE_ARGS+=	-DWITH_ARTS:BOOL=OFF
CMAKE_ARGS+=	-DBUILD_KSAYIT:BOL=OFF
CMAKE_ARGS+=	-DBUILD_KSAYIT_FREEVERB:BOL=OFF
.endif
