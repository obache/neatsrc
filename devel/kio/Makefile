# $NetBSD: Makefile,v 1.15 2017/11/30 16:45:02 adam Exp $

DISTNAME=	kio-${KF5VER}
PKGREVISION=	11
CATEGORIES=	devel

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Resource and network access abstraction
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

USE_TOOLS+=	msgmerge

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kio/accept-languages.codes \
		${PKG_SYSCONFDIR}/xdg/accept-languages.codes
CONF_FILES+=	${PREFIX}/share/examples/kio/kshorturifilterrc \
		${PKG_SYSCONFDIR}/xdg/kshorturifilterrc

#.include "../../lang/python/tool.mk"
#.include "../../wip/gpgmepp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../archivers/karchive/buildlink3.mk"
.include "../../devel/kbookmarks/buildlink3.mk"
.include "../../devel/kdoctools/buildlink3.mk"
.include "../../security/kwallet/buildlink3.mk"
.include "../../sysutils/solid/buildlink3.mk"
.include "../../x11/kjobwidgets/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
