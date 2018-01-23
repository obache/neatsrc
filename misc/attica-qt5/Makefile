# $NetBSD: Makefile,v 1.8 2018/01/17 20:04:45 markd Exp $

DISTNAME=	attica-${KF5VER}
PKGNAME=	${DISTNAME:S/-/-qt5-/}
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Qt5 library that implements the Open Collaboration Services API
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

PKGCONFIG_OVERRIDE+=	src/cmake/libKF5Attica.pc.cmake

INSTALLATION_DIRS+=	share/examples/${PKGBASE}
MAKE_DIRS+=		${PKG_SYSCONFDIR}/xdg

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/xdg ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}

CONF_FILES+=	share/examples/${PKGBASE}/xdg/attica.categories ${PKG_SYSCONFDIR}/xdg/attica.categories

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
