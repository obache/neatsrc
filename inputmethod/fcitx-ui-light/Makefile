# $NetBSD$

DISTNAME=	fcitx-ui-light-0.1.3
CATEGORIES=	inputmethod
MASTER_SITES=	http://download.fcitx-im.org/fcitx-ui-light/
EXTRACT_SUFX=	.tar.bz2

HOMEPAGE=	http://fcitx-im.org/
COMMENT=	Very light weight ui for fcitx
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	intltool msgfmt msgmerge pkg-config

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../inputmethod/fcitx/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
