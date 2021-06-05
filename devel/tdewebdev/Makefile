# $NetBSD$

TDE_PKGNAME=	tdewebdev
CATEGORIES=	devel

COMMENT=	Web Development packages for Trinity Desktop Environment
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	tqt3-tools>=${TQT3_RELEASE}:../../x11/tqt3-tools
DEPENDS+=	tidy-[0-9]*:../../www/tidy
DEPENDS+=	tdeutils=>${_TDE_RELEASE}:../../misc/tdeutils

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config perl perl:run wget:run


.include "../../meta-pkgs/tde/Makefile.tde"

CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=TRUE
CMAKE_ARGS+=	-DBUILD_ALL:BOOL=ON
CMAKE_ARGS+=	-DWITH_QUANTA_CVSSERVICE:BOOL=ON
CMAKE_ARGS+=	-DWITH_OTHER_EDITORS:BOOL=ON

REPLACE_PERL+=	kommander/working/extractkmdr

.include "../../devel/tdesdk/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"

.include "../../x11/tdelibs/buildlink3.mk"
.include "../../x11/tqtinterface/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
