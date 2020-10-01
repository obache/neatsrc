# $NetBSD$

BUILDLINK_TREE+=	arts

.if !defined(ARTS_BUILDLINK3_MK)
ARTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.arts+=	arts>=14.0.4
BUILDLINK_PKGSRCDIR.arts?=	../../audio/arts

.include "../../devel/glib2/buildlink3.mk"

pkgbase := arts
.include "../../mk/pkg-build-options.mk"

# ALSA support
.if !empty(PKG_BUILD_OPTIONS.arts:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

# AUDIOFILE support
.if !empty(PKG_BUILD_OPTIONS.arts:Maudiofile)
.include "../../audio/libaudiofile/buildlink3.mk"
.endif

# ESOUND support
.if !empty(PKG_BUILD_OPTIONS.arts:Mesound)
.include "../../audio/esound/buildlink3.mk"
.endif

# JACK support
.if !empty(PKG_BUILD_OPTIONS.arts:Mjack)
.include "../../audio/jack/buildlink3.mk"
.endif

# MAD support
.if !empty(PKG_BUILD_OPTIONS.arts:Mmad)
.include "../../audio/libmad/buildlink3.mk"
.endif

# Ogg/Vorbis support
.if !empty(PKG_BUILD_OPTIONS.arts:Mvorbis)
.include "../../audio/libvorbis/buildlink3.mk"
.endif

# SNDIO support
#.if !empty(PKG_BUILD_OPTIONS.arts:Msndio)
#.include "../../audio/sndio/buildlink3.mk"
#.endif

.endif	# ARTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-arts
