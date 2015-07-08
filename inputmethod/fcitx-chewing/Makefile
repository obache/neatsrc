# $NetBSD$

DISTNAME=	fcitx-chewing-0.2.2
CATEGORIES=	inputmethod chinese
MASTER_SITES=	http://download.fcitx-im.org/fcitx-chewing/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://fcitx-im.org/
COMMENT=	Chewing Wrapper for Fcitx
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt pkg-config

ICON_THEMES=	yes

.include "../../inputmethod/fcitx/buildlink3.mk"
.include "../../inputmethod/libchewing/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
