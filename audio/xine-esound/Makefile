# $NetBSD: Makefile,v 1.51 2019/11/02 21:09:18 rillig Exp $

PKGREVISION= 2
.include "../../multimedia/xine-lib/Makefile.common"

PKGNAME=	${XINE_PKGNAME:S/lib/esound/}
CATEGORIES=	audio
COMMENT=	The esound audio output plugin for xine-lib

BUILD_DIRS=		src/audio_out
CONFIGURE_ARGS+=	--without-x --disable-xinerama
CONFIGURE_ARGS+=	--disable-vcd
CONFIGURE_ARGS+=	--disable-coreaudio
CONFIGURE_ARGS+=	--disable-oss
CONFIGURE_ARGS+=	--disable-sunaudio
CONFIGURE_ARGS+=	--without-alsa
CONFIGURE_ARGS+=	--without-jack
CONFIGURE_ARGS+=	--without-pulseaudio
CONFIGURE_ARGS+=	--with-esound

post-configure:
	${LN} -s ${BUILDLINK_PREFIX.xine-lib}/lib/libxine.la ${WRKSRC}/src/xine-engine/

.include "../../audio/esound/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
