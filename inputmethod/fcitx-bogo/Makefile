# $NetBSD$

DISTNAME=	fcitx-bogo-0.1.2
CATEGORIES=	inputmethod
MASTER_SITES=	-https://github.com/BoGoEngine/fcitx-bogo/archive/v${PKGVERSION_NOREV}.tar.gz

HOMEPAGE=	https://github.com/BoGoEngine/fcitx-bogo/
COMMENT=	Fcitx bridge for BoGo - a Vietnamese IME
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../inputmethod/fcitx/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
