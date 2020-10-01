# $NetBSD$

TDE_PKGNAME=	dbus-tqt
CATEGORIES=	sysutils
TDE_SUBDIR=	dependencies

COMMENT=	DBus bindings for TQt
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	tqt3-tools>=${TQT3_RELEASE}:../../x11/tqt3-tools

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=TRUE

PKGCONFIG_OVERRIDE+=	dbus-tqt.pc.cmake

.include "../../meta-pkgs/tde/Makefile.tde"

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/tqtinterface/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
