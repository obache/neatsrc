# $NetBSD$

TDE_PKGNAME=	tdevelop
CATEGORIES=	devel

COMMENT=	Integrated Development Environment for Trinity Desktop Environment
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	tqt3-tools>=${TQT3_RELEASE}:../../x11/tqt3-tools

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config gtar perl:run
EXTRACT_USING=	gtar

.include "../../meta-pkgs/tde/Makefile.tde"

CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=TRUE
CMAKE_ARGS+=	-DBUILD_ALL:BOOL=ON
CMAKE_ARGS+=	-DTAR:PATH=${GTAR}
CMAKE_ARGS+=	-DQT_DOCDIR:PATH=${TQTDIR}/doc/html

CMAKE_ARGS+=	-DWITH_LANGUAGE_ALL:BOOL=ON
CMAKE_ARGS+=	-DWITH_VCS_ALL:BOOL=ON

REPLACE_PERL+=	kdevprj2kdevelop

#svn
.include "../../devel/apr/buildlink3.mk"
.include "../../devel/subversion-base/buildlink3.mk"
#cvs
.include "../../devel/tdesdk/buildlink3.mk"

.include "../../x11/tqt3-tools/buildlink3.mk"
.include "../../x11/tdelibs/buildlink3.mk"
.include "../../x11/tqtinterface/buildlink3.mk"
CMAKE_ARGS+=	-DUSE_DB_H_PATH:FILEPATH=${BDB_TYPE}/db.h
CMAKE_ARGS+=	-DBDB_LIBRARY:FILEPATH=${BDB_TYPE}
BDB_ACCEPTED=	db4 db5
.include "../../mk/bdb.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
