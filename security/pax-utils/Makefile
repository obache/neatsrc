# $NetBSD$

DISTNAME=	pax-utils-1.2.4
CATEGORIES=	security sysutils devel
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/}
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	https://wiki.gentoo.org/wiki/Hardened/PaX_Utilities
COMMENT=	ELF/PaX Utilities
LICENSE=	gnu-gpl-v2

TEST_DEPENDS+=	${PYPKGPREFIX}-pyelftools-[0-9]*:../../devel/py-pyelftools

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake bash:run
USE_LIBTOOL=	yes

REPLACE_BASH+=	lddtree.sh symtree.sh
REPLACE_BASH+=	tests/lddtree/dotest-cmp
REPLACE_BASH+=	tests/lddtree/dotest-py
REPLACE_BASH+=	tests/lddtree/dotest-sfx
REPLACE_BASH+=	tests/lddtree/dotest-sh
REPLACE_BASH+=	tests/scanelf/dotest
REPLACE_BASH+=	tests/source/dotest
REPLACE_PYTHON+=lddtree.py

SUBST_CLASSES+=		bash-path
SUBST_STAGE.bash-path=	pre-configure
SUBST_SED.bash-path=	-e s,/bin/bash,${BASH:Q},g
SUBST_FILES.bash-path+=	tests/lddtree/dotest-cmp
SUBST_FILES.bash-path+=	tests/lddtree/dotest-sfx

TEST_TARGET=	check

PYTHON_FOR_BUILD_ONLY=	test
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
