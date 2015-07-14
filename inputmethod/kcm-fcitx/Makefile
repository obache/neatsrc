# $NetBSD$

DISTNAME=	kcm-fcitx-0.4.3
CATEGORIES=	inputmethod kde
MASTER_SITES=	http://download.fcitx-im.org/kcm-fcitx/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://fcitx-im.org/
COMMENT=	KDE config Module for Fcitx
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt pkg-config

USE_FCITX_QT_GUI=	yes
.include "../../inputmethod/fcitx/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
