# $NetBSD$

DISTNAME=	ibus-bogo_0.4.0
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	inputmethod
MASTER_SITES=	https://github.com/BoGoEngine/ibus-bogo/releases/download/v${PKGVERSION_NOREV}/
HOMEPAGE=	http://github.com/BoGoEngine/ibus-bogo
COMMENT=	IBus frontend for BoGo engine
LICENSE=	gnu-gpl-v3

DEPENDS+=	ibus-[0-9]*:../../inputmethod/ibus
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-qt4-[0-9]*:../../x11/py-qt4
DEPENDS+=	libnotify-[0-9]*:../../sysutils/libnotify
DEPENDS+=	libwnck3-[0-9]*:../../devel/libwnck3

WRKSRC=		${WRKDIR}/ibus-bogo
USE_CMAKE=	yes
USE_LANGUAGES=	# none

SUBST_CLASSES+=		qt4
SUBST_STAGE.qt4=	pre-configure
SUBST_FILES.qt4=	gui/CMakeLists.txt
SUBST_SED.qt4+=		-e 's,lrelease-qt4,${QTDIR}/bin/lrelease,'

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-build
SUBST_FILES.paths+=	gui/ibus-bogo-settings
SUBST_FILES.paths+=	gui/ibus-setup-bogo.desktop
SUBST_FILES.paths+=	ibus_engine/data/bogo.xml
SUBST_FILES.paths+=	ibus_engine/data/ibus-engine-bogo
SUBST_FILES.paths+=	ibus_engine/ibus_engine.py
SUBST_SED.paths+=	-e 's,env python3 ,exec ${PYTHONBIN} ,g'
SUBST_SED.paths+=	-e 's,python3 ,${PYTHONBIN} ,g'
SUBST_SED.paths+=	-e 's,/usr/share,${PREFIX}/share,g'
SUBST_SED.paths+=	-e 's,/usr/lib,${PREFIX}/lib,g'

REPLACE_SH+=	gui/ibus-bogo-settings
REPLACE_SH+=	ibus_engine/data/ibus-engine-bogo

PYTHON_VERSIONS_INCOMPATIBLE=	27
.include "../../lang/python/application.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
