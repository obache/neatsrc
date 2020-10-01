# $NetBSD$

TDE_PKGNAME=	tqtinterface
CATEGORIES=	x11
TDE_SUBDIR=	dependencies
COMMENT=	Trinity QT interface
LICENSE=	gnu-gpl-v2

DEPENDS+=	tqt3-tools>=${TQT3_RELEASE}:../../x11/tqt3-tools

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	bash:run

.include "../../meta-pkgs/tde/Makefile.tde"

CMAKE_ARGS+=		-DWITH_QT3:BOOL=ON
CMAKE_ARGS+=		-DMOC_EXECUTABLE:FILEPATH="${TQTDIR}/bin/tqmoc"
CMAKE_ARGS+=		-DQT_LIBRARY_DIR:FILEPATH="${TQTDIR}/lib"
CMAKE_ARGS+=		-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=TRUE

REPLACE_BASH+=	cmake/install_apidox
REPLACE_BASH+=	cmake/generate_apidox
REPLACE_BASH+=	qtinterface/tqt-replace-tqt3.cmake
REPLACE_BASH+=	qtinterface/parser.sh
REPLACE_BASH+=	qtinterface/tqt-replace.cmake
REPLACE_BASH+=	qtinterface/convert_qt_tqt2
REPLACE_BASH+=	qtinterface/convert_qt_tqt3
REPLACE_BASH+=	qtinterface/moc-tqt
REPLACE_BASH+=	qtinterface/tqt-replace-stream-tqt3.cmake
REPLACE_BASH+=	qtinterface/interface_tqt3/tmoc.cmake
REPLACE_BASH+=	qtinterface/tqt-replace-stream.cmake
REPLACE_BASH+=	qtinterface/interface_qt3/tmoc.cmake
REPLACE_BASH+=	qtinterface/uic-tqt.cmake
REPLACE_BASH+=	qtinterface/parser2.sh
REPLACE_BASH+=	qtinterface/parser2.sh
REPLACE_BASH+=	qtinterface/tqt-replace
REPLACE_BASH+=	qtinterface/mcopidl-tqt
REPLACE_BASH+=	qtinterface/tqt-replace-stream
REPLACE_BASH+=	qtinterface/dcopidl2cpp-tqt
REPLACE_BASH+=	qtinterface/parser3.sh
REPLACE_BASH+=	qtinterface/dcopidl-tqt
REPLACE_BASH+=	qtinterface/dcopidlng-tqt
REPLACE_BASH+=	qtinterface/convert_qt_tqt1

PKGCONFIG_OVERRIDE+=		${WRKDIR}/build/qtinterface/tqt.pc
PKGCONFIG_OVERRIDE+=		${WRKDIR}/build/qtinterface/tqtqui.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

.include "../../x11/tqt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
