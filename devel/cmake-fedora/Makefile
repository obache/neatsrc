# $NetBSD: Makefile,v 1.12 2017/11/01 06:44:49 maya Exp $

DISTNAME=	cmake-fedora-2.9.2-Source
PKGNAME=	${DISTNAME:S/-Source//}
CATEGORIES=	devel
MASTER_SITES=	https://releases.pagure.org/cmake-fedora/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pagure.io/cmake-fedora
COMMENT=	Set of cmake modules for fedora developers
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_TOOLS+=	cmake:run bash:run
USE_LANGUAGES=	# none

CMAKE_ARGS+=	-DCMAKE_FEDORA_ENABLE_FEDORA_BUILD=0

NO_BUILD=	yes

TEST_TARGET=	test_all

.include "../../devel/cmake/Makefile.version"
PLIST_SUBST+=	CMAKE_API=${CMAKE_API}
PRINT_PLIST_AWK+=	/^share\/cmake-${CMAKE_API}/ \
			{ gsub(/cmake-${CMAKE_API}/, "cmake-$${CMAKE_API}") }

SUBST_CLASSES+=		syscfdir
SUBST_STAGE.syscfdir=	pre-configure
SUBST_SED.syscfdir+=	-e 's,/etc,${PKG_SYSCONFDIR},g'
SUBST_FILES.syscfdir+=	Modules/ManageFile.cmake
SUBST_FILES.syscfdir+=	Modules/ManageEnvironmentCommon.cmake

REPLACE_BASH+=	scripts/cmake-fedora-fedpkg
REPLACE_BASH+=	scripts/cmake-fedora-koji
REPLACE_BASH+=	scripts/cmake-fedora-pkgdb
REPLACE_BASH+=	scripts/cmake-fedora-reset
REPLACE_BASH+=	scripts/cmake-fedora-zanata
REPLACE_BASH+=	scripts/koji-build-scratch

INSTALLATION_DIRS+=	share/examples

post-install:
		${MV} ${DESTDIR}${PKG_SYSCONFDIR} ${DESTDIR}${PREFIX}/share/examples/cmake-fedora

CONF_FILES+=	share/examples/cmake-fedora/cmake-fedora.conf ${PKG_SYSCONFDIR}/cmake-fedora.conf

.include "../../mk/bsd.pkg.mk"
