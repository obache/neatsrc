# $NetBSD$

TDE_PKGNAME=	tdeadmin
CATEGORIES=	x11

COMMENT=	Trinity Desktop Environment [TDE] admin tools
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	tqt3-tools>=${TQT3_RELEASE}:../../x11/tqt3-tools

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config perl:run

.include "options.mk"

.include "../../meta-pkgs/tde/Makefile.tde"

REPLACE_PERL+=	knetworkconf/backends/*.pl.in	
REPLACE_PERL+=	knetworkconf/backends/network-conf.in

PKGCONFIG_OVERRIDE+=	knetworkconf/backends/system-tools-backends.pc.in

CMAKE_ARGS+=	-DBUILD_ALL:BOOL=ON
CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=ON

.include "../../x11/tqtinterface/buildlink3.mk"
.include "../../x11/tdelibs/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
