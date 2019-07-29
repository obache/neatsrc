# $NetBSD: Makefile,v 1.20 2019/07/21 22:25:08 wiz Exp $
#

PKGNAME=		fcitx-4.2.9.6
PKGREVISION=		5
DISTNAME=		${PKGNAME_NOREV}_dict
CATEGORIES=		inputmethod chinese
MASTER_SITES=		https://download.fcitx-im.org/fcitx/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		rxg@NetBSD.org
HOMEPAGE=		http://fcitx-im.org/
COMMENT=		Flexible input method framework
LICENSE=		gnu-gpl-v2 AND gnu-lgpl-v2.1

TOOL_DEPENDS+=	extra-cmake-modules>=0.0.11:../../devel/extra-cmake-modules
DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils # xdg-open

USE_CMAKE=		yes
USE_LANGUAGES=		c99 c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		bash:run gmake intltool msgfmt pkg-config gettext:run

PKGCONFIG_OVERRIDE+=	src/lib/*/*.pc.in

#CMAKE_ARGS+=	-DENABLE_PINYIN=OFF
#CMAKE_ARGS+=	-DENABLE_TABLE=OFF
#CMAKE_ARGS+=	-DENABLE_OPENCC=OFF
CMAKE_ARGS+=	-DENABLE_TEST=ON
CMAKE_ARGS+=	-DSYSCONFDIR:PATH=${PREFIX}/share/examples/${PKGBASE}
CMAKE_ARGS+=	-DMAN_INSTALL_DIR:PATH=${PREFIX}/${PKGMANDIR}

WRKSRC=	${WRKDIR}/${PKGNAME_NOREV}

REPLACE_BASH+=	data/script/fcitx-diagnose.sh
REPLACE_BASH+=	cmake/fcitx-cmake-helper.sh
REPLACE_BASH+=	cmake/fcitx-extract-confdesc.sh
REPLACE_BASH+=	cmake/fcitx-extract-desktop.sh
REPLACE_BASH+=	cmake/fcitx-extract-gettext.sh
REPLACE_BASH+=	cmake/fcitx-extract-kde.sh
REPLACE_BASH+=	cmake/fcitx-extract-po.sh
REPLACE_BASH+=	cmake/fcitx-extract-qt.sh
REPLACE_BASH+=	cmake/fcitx-merge-config.sh

.include "options.mk"

CONF_FILES+=	\
	${PREFIX}/share/examples/${PKGBASE}/xdg/autostart/fcitx-autostart.desktop \
	${PKG_SYSCONFDIR}/xdg/autostart/fcitx-autostart.desktop

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus+=	dbus>=1.1.0
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/xkeyboard-config/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
