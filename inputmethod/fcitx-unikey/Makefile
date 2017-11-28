# $NetBSD$

DISTNAME=	fcitx-unikey-0.2.7
CATEGORIES=	inputmethod
MASTER_SITES=	http://download.fcitx-im.org/fcitx-unikey/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://fcitx-im.org/
COMMENT=	Unikey (Vietnamese Input Method) engine support for Fcitx
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt pkg-config

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../inputmethod/fcitx/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
