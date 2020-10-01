# $NetBSD$

TDE_PKGNAME=	avahi-tqt
CATEGORIES=	net
TDE_SUBDIR=	dependencies

COMMENT=	Avahi bindings for TQt
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	tqt3-tools>=${TQT3_RELEASE}:../../x11/tqt3-tools

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=YES

PKGCONFIG_OVERRIDE+=	avahi-tqt.pc.cmake

.include "../../meta-pkgs/tde/Makefile.tde"

.include "../../net/avahi/buildlink3.mk"
.include "../../x11/tqtinterface/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
