# $NetBSD$

TDE_PKGNAME=	dbus-1-tqt
PKGNAME=	dbus1-tqt-${_TDE_RELEASE}
CATEGORIES=	sysutils
TDE_SUBDIR=	dependencies

COMMENT=	Backported Qt4 DBUS bindings for TQt
LICENSE=	gnu-gpl-v2


BUILD_DEPENDS+=	tqt3-tools>=${TQT3_RELEASE}:../../x11/tqt3-tools

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../meta-pkgs/tde/Makefile.tde"

PKGCONFIG_OVERRIDE+=	dbus-1-tqt.pc.cmake

CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=TRUE

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/tqtinterface/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
