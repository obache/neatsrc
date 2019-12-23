# $NetBSD: Makefile,v 1.44 2019/11/02 21:09:18 rillig Exp $
#

PKGREVISION= 3
.include "../../multimedia/xine-lib/Makefile.common"

PKGNAME=	${XINE_PKGNAME:S/lib/pulse/}
CATEGORIES=	audio
COMMENT=	The PulseAudio output plugin for xine-lib

BUILD_DIRS=		src/audio_out
CONFIGURE_ARGS+=	--without-x --disable-xinerama
CONFIGURE_ARGS+=	--disable-vcd
CONFIGURE_ARGS+=	--disable-coreaudio
CONFIGURE_ARGS+=	--disable-oss
CONFIGURE_ARGS+=	--disable-sunaudio
CONFIGURE_ARGS+=	--without-esound
CONFIGURE_ARGS+=	--without-alsa
CONFIGURE_ARGS+=	--without-jack
CONFIGURE_ARGS+=	--with-pulseaudio

post-configure:
	${LN} -s ${BUILDLINK_PREFIX.xine-lib}/lib/libxine.la ${WRKSRC}/src/xine-engine/

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
