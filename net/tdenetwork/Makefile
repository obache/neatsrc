# $NetBSD$

TDE_PKGNAME=	tdenetwork
CATEGORIES=	x11

COMMENT=	Trinity Desktop Environment [TDE] network
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	tqt3-tools>=${TQT3_RELEASE}:../../x11/tqt3-tools

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config perl:run bash:run
EXTRACT_USING=	gtar

.include "../../meta-pkgs/tde/Makefile.tde"

CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=TRUE
CMAKE_ARGS+=	-DSYSCONF_INSTALL_DIR=${PKG_SYSCONFDIR}

CMAKE_ARGS+=	-DBUILD_ALL:BOOL=TRUE
# iwlib>=27
CMAKE_ARGS+=	-DBUILD_WIFI:BOOL=FALSE

REPLACE_PERL+=	ksirc/dsirc
REPLACE_BASH+=	krfb/krfb_httpd/krfb_httpd
REPLACE_PERL+=	kopete/kopete/tdeconf_update/kopete-account-0.10.pl
REPLACE_PERL+=	kopete/kopete/tdeconf_update/kopete-pluginloader.pl
REPLACE_PERL+=	knewsticker/knt-0.1-0.2.pl

PKG_EXAMPLES_DIR=	share/examples/${PKGBASE}
INSTALLATION_DIRS+=	${PKG_EXAMPLES_DIR}

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/${PKG_EXAMPLES_DIR}
	${MV} ${DESTDIR}${PKG_SYSCONFDIR} ${DESTDIR}${PREFIX}/${PKG_EXAMPLES_DIR}

MAKE_DIRS+=	${PKG_SYSCONFBASE}/ppp/peers

PKG_CONF_FILES+=	ppp/peers/kppp-options

.for c in ${PKG_CONF_FILES}
CONF_FILES+=	${PKG_EXAMPLES_DIR}/$c ${PKG_SYSCONFDIR}/$c
.endfor

#krfb
.include "../../x11/libXtst/buildlink3.mk"

.include "../../x11/tdelibs/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
