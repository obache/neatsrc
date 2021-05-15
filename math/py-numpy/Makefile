# $NetBSD: Makefile,v 1.78 2021/04/20 20:53:48 thor Exp $

DISTNAME=	numpy-1.19.5
PKGREVISION=	4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/numpy/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.numpy.org/
COMMENT=	Array processing for numbers, strings, records, and objects
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
BUILD_DEPENDS+=	${PYPKGPREFIX}-cython>=0.29.21:../../devel/py-cython
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

# error: 'for' loop initial declarations are only allowed in C99 mode
USE_LANGUAGES=		c99 fortran

.include "../../math/py-numpy/Makefile.make_env"

REPLACE_PYTHON+=	*.py */*.py */*/*.py */*/*/*.py

PYTHON_VERSIONS_INCOMPATIBLE=	27 # since 1.17

# XXX Avoid picking up other compilers when installed
.include "../../mk/compiler.mk"

.if defined(PKGSRC_FORTRAN) && ${PKGSRC_FORTRAN} == "g95"
PYSETUPBUILDARGS+=	--fcompiler=g95
.elif defined(PKGSRC_FORTRAN) && ${PKGSRC_FORTRAN} == "gfortran"
PYSETUPBUILDARGS+=	--fcompiler=gnu95
.elif !empty(PKGSRC_COMPILER:Mgcc)
PYSETUPBUILDARGS+=	--fcompiler=gnu
.endif

# This package bypasses the wrappers and calls the compilers directly when
# linking, so ensure that we pass through requisite options.
LDFLAGS+=		${_COMPILER_ABI_FLAG.${ABI}}

.include "../../mk/bsd.prefs.mk"

# numpy fails using the gold linker with:
# fatal error: --sysroot=: must take a non-empty argument
# Work around it on DragonFly by specifying the classic gnu linker
MAKE_ENV.DragonFly+=	LDVER=ld.bfd

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${RM} f2py f2py2 f2py3 || ${TRUE}

do-test:
	${RUN}cd ${WRKSRC};${PYTHONBIN} runtests.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
# BLAS with CBLAS is needed for proper acceleration.
.include "../../math/cblas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
