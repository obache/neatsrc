# $NetBSD$

TDE_PKGNAME=	arts
CATEGORIES=	audio
TDE_SUBDIR=	dependencies

COMMENT=	Analog Real-Time Synthesizer
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

BUILD_DEPENDS+=	tqt3-tools>=${TQT3_RELEASE}:../../x11/tqt3-tools

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

# intentionally overrides libc
FORTIFY_SUPPORTED=	no

.include "../../meta-pkgs/tde/Makefile.tde"

CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH:PATH=${PREFIX:Q}/lib
CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=ON

PKGCONFIG_OVERRIDE+=	artsc/artsc.pc.in
PKGCONFIG_OVERRIDE+=	arts.pc.cmake

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/tqtinterface/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
CMAKE_ARGS+=	-DLIBOSSAUDIO=${LIBOSSAUDIO:Q}
.include "../../mk/bsd.pkg.mk"
