# $NetBSD$

DISTNAME=	fcitx-sayura-0.1.1
CATEGORIES=	inputmethod
MASTER_SITES=	http://download.fcitx-im.org/fcitx-sayura/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://fcitx-im.org/
COMMENT=	Sayura Sinhala Input Method For Fcitx
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt pkg-config

ICON_THEMES=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/fcitx/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
