# $NetBSD: Makefile,v 1.6 2020/01/10 21:13:55 joerg Exp $

DISTNAME=	fcitx-qt5-1.2.4
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx-qt5/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://fcitx-im.org/
COMMENT=	Fcitx Qt5 Input Context
LICENSE=	gnu-gpl-v2 AND modified-bsd

TOOL_DEPENDS+=	extra-cmake-modules>=1.4.0:../../devel/extra-cmake-modules

BUILD_DEPENDS+=	extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules

USE_TOOLS+=	pkg-config
USE_CMAKE=	yes
USE_LANGUAGES=	c c++11
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=TRUE

PTHREAD_AUTO_VARS=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/fcitx/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
