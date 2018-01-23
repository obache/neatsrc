# $NetBSD: Makefile,v 1.14 2018/01/17 20:11:05 markd Exp $

DISTNAME=	kcodecs-${KF5VER}
CATEGORIES=	textproc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Provide a collection of methods to manipulate strings using various encodings
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

INSTALLATION_DIRS+=	share/examples/${PKGBASE}
MAKE_DIRS+=		${PKG_SYSCONFDIR}/xdg

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/xdg ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}

CONF_FILES+=	share/examples/${PKGBASE}/xdg/${PKGBASE}.categories ${PKG_SYSCONFDIR}/xdg/${PKGBASE}.categories

.include "../../meta-pkgs/kf5/Makefile.common"

.include "../../x11/qt5-qtbase/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
