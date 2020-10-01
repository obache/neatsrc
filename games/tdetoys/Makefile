# $NetBSD$

TDE_PKGNAME=	tdetoys
CATEGORIES=	games

COMMENT=	Trinity Desktop Environment [TDE] toys
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	tqt3-tools>=${TQT3_RELEASE}:../../x11/tqt3-tools

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../meta-pkgs/tde/Makefile.tde"

CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=TRUE
CMAKE_ARGS+=	-DBUILD_ALL:BOOL=ON

.include "../../x11/tdelibs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
