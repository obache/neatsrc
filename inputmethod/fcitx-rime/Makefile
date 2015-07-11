# $NetBSD$

DISTNAME=	fcitx-rime-0.3.1
CATEGORIES=	inputmethod chinese
MASTER_SITES=	http://download.fcitx-im.org/fcitx-rime/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://fcitx-im.org/
COMMENT=	RIME support for Fcitx
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt pkg-config

ICON_THEMES=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/fcitx/buildlink3.mk"
.include "../../inputmethod/librime/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
