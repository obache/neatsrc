# $NetBSD$

TDE_PKGNAME=	tdeaddons
CATEGORIES=	misc

COMMENT=	Trinity Desktop Environment [TDE] addons
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	tqt3-tools>=${TQT3_RELEASE}:../../x11/tqt3-tools

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config perl:run

.include "../../meta-pkgs/tde/Makefile.tde"

CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=TRUE
CMAKE_ARGS+=	-DBUILD_ALL:BOOL=TRUE

REPLACE_PERL+=	konq-plugins/mediarealfolder/tdeio_media_realfolder
REPLACE_PYTHON+=konq-plugins/imagerotation/exif.py
REPLACE_PYTHON+=konq-plugins/imagerotation/orient.py

.include "options.mk"

PKG_EXAMPLES_DIR=	share/examples/${PKGBASE}
INSTALLATION_DIRS+=	${PKG_EXAMPLES_DIR}

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/${PKG_EXAMPLES_DIR}
	${MV} ${DESTDIR}${PKG_SYSCONFDIR} ${DESTDIR}${PREFIX}/${PKG_EXAMPLES_DIR}

PKG_CONF_FILES+=	translaterc

.for c in ${PKG_CONF_FILES}
CONF_FILES+=	${PKG_EXAMPLES_DIR}/${c} ${PKG_SYSCONFDIR}/${c}
.endfor

.include "../../games/tdegames/buildlink3.mk"
.include "../../misc/tdepim/buildlink3.mk"
.include "../../multimedia/tdemultimedia/buildlink3.mk"
.include "../../x11/tqtinterface/buildlink3.mk"
.include "../../x11/tdebase/buildlink3.mk"
.include "../../x11/tdelibs/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
