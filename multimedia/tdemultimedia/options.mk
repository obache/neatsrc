# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.tdemultimedia
PKG_SUPPORTED_OPTIONS=	vorbis alsa cdparanoia lame taglib
PKG_SUPPORTED_OPTIONS+=	musicbrainz gstreamer theora flac
PKG_OPTIONS.arts=	akode audiofile xine
.if !empty(PKG_BUILD_OPTIONS.tdelibs:Marts)
PKG_SUPPORTED_OPTIONS+=	${PKG_OPTIONS.arts}
PLIST.arts=		yes
CMAKE_ARGS+=		-DWITH_ARTS_MPEGLIB:BOOL=ON
.endif
PKG_SUGGESTED_OPTIONS=	${PKG_SUPPORTED_OPTIONS:Nakode:Nmusicbrainz:Nalsa}
PKG_SUGGESTED_OPTIONS.Linux=	alsa

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}
PLIST_VARS+=		arts juk

_BLDIR.vorbis=		audio/libvorbis
_BLDIR.alsa=		audio/alsa-lib
_BLDIR.cdparanoia=	audio/cdparanoia
_BLDIR.lame=		audio/lame
_BLDIR.taglib=		audio/taglib
_BLDIR.akode=		audio/akode
_BLDIR.audiofile=	audio/libaudiofile
_BLDIR.musicbrainz=	audio/libtunepimp
_BLDIR.gstreamer=	multimedia/gstreamer1
_BLDIR.theora=		multimedia/libtheora
_BLDIR.flac=		audio/flac
_BLDIR.xine=		multimedia/xine-lib

.include "../../mk/bsd.options.mk"

.for o in ${PKG_SUPPORTED_OPTIONS}

.  if !empty(PKG_OPTIONS.arts:M${o})
_CMAKE_ARGNAME.${o}=	WITH_ARTS_${o:tu}
.  else
_CMAKE_ARGNAME.${o}=	WITH_${o:tu}
.  endif
.  if !empty(PKG_OPTIONS:M${o})
.    for bl in ${_BLDIR.${o}}
.include "../../${bl}/buildlink3.mk"
.    endfor
CMAKE_ARGS+=	-D${_CMAKE_ARGNAME.${o}}:BOOL=ON
PLIST.${o}=		yes
.  else
CMAKE_ARGS+=	-D${_CMAKE_ARGNAME.${o}}:BOOL=OFF
.  endif

.endfor

.if !empty(PKG_OPTIONS:Mcdparanoia)
CMAKE_ARGS+=	-DCDPARANOIA_INCLUDE_DIR:PATH=${BUILDLINK_DIR}/${BUILDLINK_INCDIRS.cdparanoia}
.endif

.if !empty(PKG_OPTIONS:Mtaglib) && !empty(PKG_OPTIONS:Mgstreamer) && !empty(PKG_OPTINS:Macode)
PLIST.juk=		yes
CMAKE_ARGS+=	-DBUILD_JUK:BOOL=ON
.else
CMAKE_ARGS+=	-DBUILD_JUK:BOOL=OFF
.endif
