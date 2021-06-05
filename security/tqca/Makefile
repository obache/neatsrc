# $NetBSD$

TDE_PKGNAME=	tqca
CATEGORIES=	security
TDE_SUBDIR=	dependencies

COMMENT=	TQt Cryptographic Architecture
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	tqt3-tools>=${TQT3_RELEASE}:../../x11/tqt3-tools

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	src/tqca.pc.cmake

.include "../../meta-pkgs/tde/Makefile.tde"

CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=TRUE

.include "../../x11/tqtinterface/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
