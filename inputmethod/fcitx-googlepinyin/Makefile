# $NetBSD$

DISTNAME=	fcitx-googlepinyin-0.1.6
CATEGORIES=	inputmethod chinese
MASTER_SITES=	http://download.fcitx-im.org/fcitx-googlepinyin/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://fcitx-im.org/
COMMENT=	GooglePinyin wrapper for Fcitx
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	intltool msgfmt msgmerge pkg-config

ICON_THEMES=	yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/fcitx/buildlink3.mk"
.include "../../inputmethod/libgooglepinyin/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
