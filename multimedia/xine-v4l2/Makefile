# $NetBSD: Makefile,v 1.24 2019/11/03 17:12:05 rillig Exp $

PKGREVISION= 2
.include "../../multimedia/xine-lib/Makefile.common"

PKGNAME=	${XINE_PKGNAME:S/lib/v4l2/}
CATEGORIES=	multimedia
COMMENT=	The v4l2 input plugin for xine-lib

BUILD_DIRS=		src/input
CONFIGURE_ARGS+=	--without-x --disable-xinerama
CONFIGURE_ARGS+=	--disable-vcd
CONFIGURE_ARGS+=	--disable-coreaudio
CONFIGURE_ARGS+=	--disable-oss
CONFIGURE_ARGS+=	--disable-sunaudio
CONFIGURE_ARGS+=	--without-alsa
CONFIGURE_ARGS+=	--without-jack
CONFIGURE_ARGS+=	--without-pulseaudio
CONFIGURE_ARGS+=	--without-esound
CONFIGURE_ARGS+=	--disable-dvb
CONFIGURE_ARGS+=	--disable-v4l
CONFIGURE_ARGS+=	--enable-v4l2

MAKE_FLAGS+=	xineplug_LTLIBRARIES="xineplug_inp_v4l2.la xineplug_inp_pvr.la"

post-configure:
	${LN} -s ${BUILDLINK_PREFIX.xine-lib}/lib/libxine.la ${WRKSRC}/src/xine-engine/

.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
