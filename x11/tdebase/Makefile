# $NetBSD$

TDE_PKGNAME=	tdebase
CATEGORIES=	x11

COMMENT=	Trinity Desktop Environment [TDE] base
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	tqt3-tools>=${TQT3_RELEASE}:../../x11/tqt3-tools

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config perl perl:run bash
EXTRACT_USING=	gtar

.include "../../meta-pkgs/tde/Makefile.tde"

CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=TRUE
CMAKE_ARGS+=	-DBUILD_ALL:BOOL=TRUE

#option( BUILD_TDEKBDLEDSYNC "Build tdekbdledsync"  ${BUILD_ALL} )
CMAKE_ARGS+=	-DBUILD_TDEKBDLEDSYNC:BOOL=FALSE

REPLACE_BASH+=	kdialog/progresscanceldemo
REPLACE_PERL+=	kcontrol/keys/convertShortcuts.pl
REPLACE_PERL+=	khelpcenter/searchhandlers/khc_docbookdig.pl.in
REPLACE_PERL+=	khelpcenter/searchhandlers/khc_htdig.pl.in
REPLACE_PERL+=	khelpcenter/searchhandlers/khc_htsearch.pl.in
REPLACE_PERL+=	khelpcenter/searchhandlers/khc_mansearch.pl
REPLACE_PERL+=	kicker/kicker/kicker-3.1-properSizeSetting.pl
REPLACE_PERL+=	kicker/kicker/kicker-3.5-taskbarEnums.pl
REPLACE_PERL+=	klipper/klipper-1-2.pl
REPLACE_PERL+=	konsole/schemaStrip.pl
REPLACE_PERL+=	tdeioslave/finger/tdeio_finger.pl
REPLACE_PERL+=	tdeioslave/fish/genfishcode.pl
REPLACE_PERL+=	tdeioslave/info/kde-info2html
REPLACE_PERL+=	twin/data/twin3_plugin.pl
REPLACE_PERL+=	twin/data/pluginlibFix.pl

.include "options.mk"

CMAKE_ARGS+=	-DBUILD_TSAK:BOOL=FALSE

PKG_EXAMPLES_DIR=	share/examples/${PKGBASE}
INSTALLATION_DIRS+=	${PKG_EXAMPLES_DIR}
INSTALLATION_DIRS+=	share/apps/tdm/faces

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/${PKG_EXAMPLES_DIR}
	${MV} ${DESTDIR}${PKG_SYSCONFDIR} ${DESTDIR}${PREFIX}/${PKG_EXAMPLES_DIR}
	${LN} -s ${PREFIX}/share/apps/tdm/pics/users/default1.png ${DESTDIR}${PREFIX}/share/apps/tdm/faces/.default.face.icon
	${LN} -s ${PREFIX}/share/apps/tdm/pics/users/root1.png ${DESTDIR}${PREFIX}/share/apps/tdm/faces/root.face.icon

MAKE_DIRS+=	${PKG_SYSCONFBASE}/xdg/menus
MAKE_DIRS+=	${PKG_SYSCONFBASE}/xdg/menus/applications-merged

PKG_CONF_FILES+=	ksysguarddrc
PKG_CONF_FILES+=	xdg/menus/applications-merged/tde-essential.menu
PKG_CONF_FILES+=	xdg/menus/tde-screensavers.menu
PKG_CONF_FILES+=	xdg/menus/tde-settings.menu
.for c in ${PKG_CONF_FILES}
CONF_FILES+=	${PKG_EXAMPLES_DIR}/$c ${PKG_SYSCONFDIR}/$c
.endfor

FONTS_DIRS.x11+=	share/apps/konsole/fonts

SUBST_CLASSES+=		defconf
SUBST_STAGE.defconf=	post-configure
SUBST_FILES.defconf=	tdm/config.def
SUBST_SED.defconf=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.defconf+=	-e 's,/opt/trinity,${CMAKE_INSTALL_PREFIX},g'
SUBST_SED.defconf+=	-e 's,/usr/X11R6,${X11BASE},g'
SUBST_SED.defconf+=	-e 's,/usr/share,${PREFIX}/share,g'

SUBST_CLASSES+=		cde-path
SUBST_STAGE.cde-path=	post-configure
SUBST_FILES.cde-path=	tdm/kfrontend/sessions/cde.desktop
SUBST_SED.cde-path=	-e 's,/usr/dt,${LOCALBASE}/dt,g'

SUBST_CLASSES+=		kde-path
SUBST_STAGE.kde-path=	post-configure
SUBST_FILES.kde-path=	tdm/kfrontend/sessions/kde-plasma.desktop
SUBST_FILES.kde-path+=	tdm/kfrontend/sessions/kde-plasma-safe.desktop
SUBST_SED.kde-path=	-e 's,/usr/bin,${LOCALBASE}/bin,g'

SUBST_CLASSES+=		sys-path
SUBST_STAGE.sys-path=	post-configure
SUBST_FILES.sys-path=	kxkb/x11helper.cpp
SUBST_FILES.sys-path+=	tdeioslave/info/kde-info2html.conf
SUBST_VARS.sys-path=	LOCALBASE X11BASE PKG_SYSCONFBASE

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-tqt/buildlink3.mk"
.include "../../sysutils/dbus1-tqt/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
USE_TOOLS+=	setxkbmap
DEPENDS+=	htdig-[0-9]*:../../www/htdig
CMAKE_ARGS+=	-DHTDIG_SEARCH_BINARY:PATH=${LOCALBASE}/libexec/cgi-bin/htdig
.include "../../x11/tqtinterface/buildlink3.mk"
.include "../../x11/tdelibs/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
