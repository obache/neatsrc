# $NetBSD: Makefile,v 1.15 2018/01/24 19:06:10 markd Exp $

DISTNAME=	kdbusaddons-${KF5VER}
PKGREVISION=	1
CATEGORIES=	sysutils

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Addons to QtDBus
LICENSE=	gnu-lgpl-v2.1

INSTALLATION_DIRS+=	share/examples/${PKGBASE}
MAKE_DIRS+=		${PKG_SYSCONFDIR}/xdg

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/xdg ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}

CONF_FILES+=	share/examples/${PKGBASE}/xdg/kdbusaddons.categories ${PKG_SYSCONFDIR}/xdg/kdbusaddons.categories

.include "../../meta-pkgs/kf5/Makefile.common"

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
