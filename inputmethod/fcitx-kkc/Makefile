# $NetBSD$

DISTNAME=	fcitx-kkc-0.1.2
CATEGORIES=	inputmethod japanese
MASTER_SITES=	http://download.fcitx-im.org/fcitx-kkc/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://fcitx-im.org/
COMMENT=	Japanese KKC input method for Fcitx
LICENSE=	gnu-gpl-v3

DEPENDS+=	skk-jisyo-[0-9]*:../../inputmethod/skk-jisyo
DEPENDS+=	libkkc-data-[0-9]*:../../misc/libkkc-data

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt pkg-config

FIND_PREFIX:=	SKK_JISYO_DIR=skk-jisyo
.include "../../mk/find-prefix.mk"
CMAKE_ARGS+=	-DSKK_DEFAULT_PATH:PATH==${SKK_JISYO_DIR}/share/skk/

BUILDLINK_TRANSFORM+=	rm:-std=c++11

ICON_THEMES=	yes

.include "../../inputmethod/fcitx/buildlink3.mk"
.include "../../converters/libkkc/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
