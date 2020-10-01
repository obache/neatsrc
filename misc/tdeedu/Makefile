# $NetBSD$

TDE_PKGNAME=	tdeedu
CATEGORIES=	misc

COMMENT=	Trinity Desktop Environment [TDE] edu tools
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	tqt3-tools>=${TQT3_RELEASE}:../../x11/tqt3-tools

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config perl:run

.include "../../meta-pkgs/tde/Makefile.tde"

REPLACE_PYTHON+=	kig/pykig/pykig.py
REPLACE_PERL+=		keduca/keduca-shrinker
REPLACE_PERL+=		kgeography/tools/gen_map.pl

CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=TRUE
CMAKE_ARGS+=	-DBUILD_DOC:BOOL=OFF
CMAKE_ARGS+=	-DPython_EXECUTABLE:FILEPATH=${PYTHONBIN}

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/tqtinterface/buildlink3.mk"
.include "../../x11/tdelibs/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
