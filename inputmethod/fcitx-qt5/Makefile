# $NetBSD$

DISTNAME=	fcitx-qt5-1.0.6
CATEGORIES=	inputmethod
MASTER_SITES=	http://download.fcitx-im.org/fcitx-qt5/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://fcitx-im.org/
COMMENT=	Fcitx Qt5 Input Context
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	extra-cmake-modules>=1.4.0:../../devel/extra-cmake-modules

USE_CMAKE=	yes
USE_LANGUAGES=	c c++11
USE_TOOLS+=	pkg-config

PTHREAD_AUTO_VARS=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/fcitx/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
