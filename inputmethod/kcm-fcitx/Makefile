# $NetBSD$

DISTNAME=	kcm-fcitx-0.5.4
CATEGORIES=	inputmethod kde
MASTER_SITES=	http://download.fcitx-im.org/kcm-fcitx/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	http://fcitx-im.org/
COMMENT=	KDE config Module for Fcitx
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	extra-cmake-modules>=1.0.0:../../devel/extra-cmake-modules

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt msgmerge pkg-config

INSTALLATION_DIRS+=	share/examples/${PKGBASE}

post-install:
	${MV} ${DESTDIR}${PREFIX}/etc/xdg ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}

CONF_FILES+=	${PREFIX}/share/examples/${PKGBASE}/xdg/fcitx-skin.knsrc \
		${PKG_SYSCONFBASEDIR}/xdg/fcitx-skin.knsrc

MAKE_DIRS+=	${PKG_SYSCONFBASEDIR}/xdg

.include "../../devel/kcmutils/buildlink3.mk"
.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../devel/ki18n/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../inputmethod/fcitx-qt5/buildlink3.mk"
.include "../../inputmethod/fcitx/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../x11/kitemviews/buildlink3.mk"
.include "../../x11/kwidgetsaddons/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
