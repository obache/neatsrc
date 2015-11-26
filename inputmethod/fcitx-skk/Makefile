# $NetBSD$

DISTNAME=	fcitx-skk-0.1.2
CATEGORIES=	inputmethod japanese
MASTER_SITES=	http://download.fcitx-im.org/fcitx-skk/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://fcitx-im.org/
COMMENT=	Skk Input Method For Fcitx
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt pkg-config

CMAKE_ARGS+=	-DSKK_DEFAULT_PATH:PATH=${LOCALBASE}/share/skk/SKK-JISYO.L

BUILDLINK_TRANSFORM+=	rm:-std=c++11

ICON_THEMES=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/fcitx/buildlink3.mk"
.include "../../inputmethod/libskk/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
