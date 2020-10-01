# $NetBSD$

TDE_PKGNAME=	tdelibs
CATEGORIES=	x11

COMMENT=	Trinity Desktop Environment [TDE] libraries
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 AND 2-clause-bsd

BUILD_DEPENDS+=	tqt3-tools>=${TQT3_RELEASE}:../../x11/tqt3-tools

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config perl perl:run iceauth:run
EXTRACT_USING=	gtar

USE_X11_RGB_TXT=	yes

.include "../../meta-pkgs/tde/Makefile.tde"
CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=TRUE
CMAKE_ARGS+=	-DICEAUTH_PATH:FILEPATH=${TOOLS_PATH.iceauth}
CMAKE_ARGS+=	-DX11_RGBFILE:FILEPATH=${PKG_RGB_TXT_PATH}

CMAKE_ARGS+=	-DWITH_TDEHWLIB:BOOL=OFF
CMAKE_ARGS+=	-DWITH_TDEHWLIB_DAEMONS:BOOL=OFF

CHECK_PORTABILITY_SKIP+=	kate/tests/highlight.sh

REPLACE_PERL+=	tdeio/misc/fileshareset
REPLACE_PERL+=	tdeui/preparetips
REPLACE_PERL+=	dcop/dcopidlng/kalyptus
REPLACE_PERL+=	tdeio/proxytype.pl
REPLACE_PERL+=	tdeio/useragent.pl

.include "options.mk"

PKG_EXAMPLES_DIR=	share/examples/${PKGBASE}
INSTALLATION_DIRS+=	${PKG_EXAMPLES_DIR}

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/${PKG_EXAMPLES_DIR}
	${MV} ${DESTDIR}${PKG_SYSCONFDIR} ${DESTDIR}${PREFIX}/${PKG_EXAMPLES_DIR}

MAKE_DIRS+=	${PKG_SYSCONFBASE}/xdg/menus

CONF_FILES+=	${PKG_EXAMPLES_DIR}/xdg/menus/tde-applications.menu \
		${PKG_SYSCONFDIR}/xdg/menus/tde-applications.menu
CONF_FILES+=	${PKG_EXAMPLES_DIR}/xdg/menus/tde-applications.menu-no-kde \
		${PKG_SYSCONFDIR}/xdg/menus/tde-applications.menu-no-kde

SPECIAL_PERMS+=	bin/fileshareset ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	bin/kgrantpty ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=	bin/kpac_dhcp_helper ${SETUID_ROOT_PERMS}

CHECK_FILES_SKIP+=	${PREFIX}/share/icons/hicolor/index.theme

SUBST_CLASSES+=		sys-path
SUBST_STAGE.sys-path=	post-configure
SUBST_FILES.sys-path=	tdeprint/lpr/matichandler.cpp
SUBST_FILES.sys-path+=	tdeprint/lpr/lprngtoolhandler.cpp
SUBST_FILES.sys-path+=	tdeprint/lpr/apshandler.cpp
SUBST_FILES.sys-path+=	tdeprint/lpr/lpchelper.cpp
SUBST_FILES.sys-path+=	tdeprint/cups/kmcupsmanager.cpp
SUBST_SED.sys-path=	-e 's,/usr/share:,${LOCALBASE}/share:/usr/share:,g'
SUBST_SED.sys-path=	-e 's,/usr/sbin:,${LOCALBASE}/sbin:/usr/sbin:,g'
SUBST_SED.sys-path=	-e 's,/usr/lib:,${LOCALBASE}/lib:/usr/lib:,g'
SUBST_SED.sys-path=	-e 's,/usr/libexec:,${LOCALBASE}/libexec:/usr/libexec:,g'

UNWRAP_CMAKE_FILES+=	../build/tdelibs.cmake

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../sysutils/dbus1-tqt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/tqtinterface/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
