# $NetBSD$

TDE_PKGNAME=	tdemultimedia
CATEGORIES=	multimedia

COMMENT=	Trinity Desktop Environment [TDE] multimedia
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	tqt3-tools>=${TQT3_RELEASE}:../../x11/tqt3-tools

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config perl:run bash:run
EXTRACT_USING=	gtar

.include "../../meta-pkgs/tde/Makefile.tde"

CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=ON
CMAKE_ARGS+=	-DBUILD_ALL:BOOL=ON

REPLACE_PERL+=	kscd/workman2cddb.pl
REPLACE_BASH+=	tdeioslave/audiocd/upgrade-metadata.sh
REPLACE_BASH+=	kaudiocreator/upgrade-kaudiocreator-metadata.sh

PKG_EXAMPLES_DIR=	share/examples/${PKGBASE}
INSTALLATION_DIRS+=	${PKG_EXAMPLES_DIR}

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/${PKG_EXAMPLES_DIR}
	${MV} ${DESTDIR}${PKG_SYSCONFDIR} ${DESTDIR}${PREFIX}/${PKG_EXAMPLES_DIR}

MAKE_DIRS+=	${PKG_SYSCONFBASE}/xdg/menus/applications-merged/

PKG_CONF_FILES+=	xdg/menus/applications-merged/tde-multimedia-music.menu

.for c in ${PKG_CONF_FILES}
CONF_FILES+=	${PKG_EXAMPLES_DIR}/$c ${PKG_SYSCONFDIR}/$c
.endfor

.include "../../x11/tqtinterface/buildlink3.mk"
.include "../../x11/tdelibs/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
CMAKE_ARGS+=	-DLIBOSSAUDIO=${LIBOSSAUDIO:Q}
.include "options.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
