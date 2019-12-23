# $NetBSD: Makefile,v 1.26 2019/11/03 17:12:04 rillig Exp $

PKGREVISION= 2
.include "../../multimedia/xine-lib/Makefile.common"

PKGNAME=	${XINE_PKGNAME:S/lib/v4l/}
CATEGORIES=	multimedia
COMMENT=	The v4l input plugin for xine-lib

# NetBSD supports only v4l2, whose plugin is in ../xine-v4l2.
NOT_FOR_PLATFORM=	NetBSD-*-*

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
CONFIGURE_ARGS+=	--disable-v4l2
CONFIGURE_ARGS+=	--enable-v4l

MAKE_FLAGS+=	xineplug_LTLIBRARIES="xineplug_inp_v4l.la"

post-configure:
	${LN} -s ${BUILDLINK_PREFIX.xine-lib}/lib/libxine.la ${WRKSRC}/src/xine-engine/

.include "../../mk/bsd.pkg.mk"
