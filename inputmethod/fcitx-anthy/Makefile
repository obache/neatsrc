# $NetBSD$

DISTNAME=	fcitx-anthy-0.2.2
CATEGORIES=	inputmethod japanese
MASTER_SITES=	http://download.fcitx-im.org/fcitx-anthy/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://fcitx-im.org/wiki/Anthy
COMMENT=	Anthy wrapper for Fcitx
LICENSE=	gnu-gpl-v2

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt pkg-config

ICON_THEMES=	yes

.include "../../inputmethod/anthy/buildlink3.mk"
.include "../../inputmethod/fcitx/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
