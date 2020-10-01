# $NetBSD$

TDE_PKGNAME=	tdegraphics
CATEGORIES=	games

COMMENT=	Trinity Desktop Environment [TDE] graphics
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	tqt3-tools>=${TQT3_RELEASE}:../../x11/tqt3-tools

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config perl:run
EXTRACT_USING=	gtar

.include "../../meta-pkgs/tde/Makefile.tde"

CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=TRUE
CMAKE_ARGS+=	-DBUILD_ALL:BOOL=ON

REPLACE_PERL+=	kghostview/update-to-xt-names.pl

PKGCONFIG_OVERRIDE+=	tdefile-plugins/dependencies/poppler-tqt/poppler-tqt.pc.cmake

.include "options.mk"

.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/libgphoto2/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../x11/tdelibs/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
