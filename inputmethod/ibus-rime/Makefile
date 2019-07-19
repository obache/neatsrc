# $NetBSD: Makefile,v 1.15 2019/07/08 10:36:27 nia Exp $

DISTNAME=	ibus-rime-1.4.0
PKGREVISION=	1
CATEGORIES=	inputmethod chinese
MASTER_SITES=	-https://github.com/rime/ibus-rime/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rime.im/
COMMENT=	Rime Input Method Engine for Linux/IBus
LICENSE=	gnu-gpl-v3

DEPENDS+=	brise>=0.38:../../inputmethod/brise

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS+=	share/ibus/component lib/ibus-rime share/ibus-rime/icons

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ibus-engine-rime ${DESTDIR}${PREFIX}/lib/ibus-rime/
	${INSTALL_DATA} ${WRKSRC}/rime.xml ${DESTDIR}${PREFIX}/share/ibus/component/
	${INSTALL_DATA} ${WRKSRC}/icons/*.png ${DESTDIR}${PREFIX}/share/ibus-rime/icons/

SUBST_CLASSES+=	dl
SUBST_STAGE.dl=	pre-configure
SUBST_FILES.dl=	CMakeLists.txt
SUBST_SED.dl=	-e 's,"dl",${BUILDLINK_LDADD.dl:S/-l//g},'

.include "../../inputmethod/librime/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
