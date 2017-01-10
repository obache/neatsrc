# $NetBSD$

DISTNAME=	fcitx-m17n-0.2.3
CATEGORIES=	inputmethod
MASTER_SITES=	http://download.fcitx-im.org/fcitx-m17n/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://fcitx-im.org/
COMMENT=	M17N IM Support For Fcitx
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt pkg-config

.include "../../devel/m17n-lib/buildlink3.mk"
.include "../../inputmethod/fcitx/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
