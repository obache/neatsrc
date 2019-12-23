# $NetBSD: Makefile,v 1.24 2019/11/02 21:09:18 rillig Exp $

PKGREVISION= 2
.include "../../multimedia/xine-lib/Makefile.common"

PKGNAME=	${XINE_PKGNAME:S/lib/alsa/}
CATEGORIES=	audio
COMMENT=	The ALSA output plugin for xine-lib

BUILD_DIRS=		src/audio_out
CONFIGURE_ARGS+=	--without-x --disable-xinerama
CONFIGURE_ARGS+=	--disable-vcd
CONFIGURE_ARGS+=	--disable-coreaudio
CONFIGURE_ARGS+=	--disable-oss
CONFIGURE_ARGS+=	--disable-sunaudio
CONFIGURE_ARGS+=	--without-esound
CONFIGURE_ARGS+=	--without-jack
CONFIGURE_ARGS+=	--without-pulseaudio
CONFIGURE_ARGS+=	--with-alsa

post-configure:
	${LN} -s ${LOCALBASE}/lib/libxine.la ${WRKSRC}/src/xine-engine/

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
